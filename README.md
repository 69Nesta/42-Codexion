*This project has been created as part of the 42 curriculum by rpetit.*

## Description

**Codexion** is a multi-threaded simulation system that models a critical resource allocation problem in software development. The project simulates multiple coders working simultaneously, competing for access to limited dongles (development tools) while managing burnout through a sophisticated scheduling system.

### Project Goal

The project demonstrates mastery of concurrent programming in C, specifically addressing:
- **Thread management** with pthreads
- **Synchronization primitives** including mutexes and condition variables
- **Resource allocation** with custom scheduling algorithms (FIFO and Earliest Deadline First)
- **Deadlock prevention** through careful lock ordering and resource management
- **Race condition mitigation** in multi-threaded environments

### Overview

The simulation consists of:
- **Coders**: Worker threads that compete for dongles to perform development tasks (compile, debug, refactor)
- **Dongles**: Limited shared resources required for compilation, with cooldown periods between uses
- **Monitor**: A dedicated thread that checks coder burnout status and manages simulation termination
- **Scheduler**: Two scheduling algorithms (FIFO and EDF) for fair dongle allocation

## Instructions

### Compilation

To compile the project:

```bash
make
```

The Makefile supports additional targets:

```bash
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Rebuild everything
```

**Compilation flags used:**
- `-Wall -Wextra -Werror`: Strict warning enforcement
- `-pthread`: Enable POSIX threading
- `-std=c89`: C89 standard compliance

### Execution

Run the simulation with the following command:

```bash
./codexion <num_coders> <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor> <num_compiles_required> <dongle_cooldown> <scheduler>
```

**Parameters:**
- `num_coders` (int): Number of coder threads (1-200)
- `time_to_burnout` (int): Milliseconds before a coder burns out without compiling (> 0)
- `time_to_compile` (int): Duration of compilation in milliseconds (> 0)
- `time_to_debug` (int): Duration of debugging in milliseconds (> 0)
- `time_to_refactor` (int): Duration of refactoring in milliseconds (> 0)
- `num_compiles_required` (int): Number of successful compiles needed per coder (> 0)
- `dongle_cooldown` (int): Cooldown period between dongle uses in milliseconds (≥ 0)
- `scheduler` (string): Scheduling algorithm - `fifo` or `edf`

**Example:**

```bash
./codexion 5 800 200 100 50 3 100 edf
```

This runs a simulation with 5 coders, 800ms burnout threshold, EDF scheduling, and other specified parameters.

### Output Format

The program outputs timestamped log entries for each action:

```
<timestamp> <coder_id> <action>
```

**Actions:**
- `has taken a dongle`: Coder acquired two dongles
- `is compiling`: Compilation phase started
- `is debugging`: Debugging phase started
- `is refactoring`: Refactoring phase started
- `burned out`: Coder reached burnout without completing compile

## Resources

### Documentation & References

- **POSIX Threads (pthreads):**
  - `man pthread_create` - Thread creation
  - `man pthread_join` - Thread joining
  - `man pthread_mutex_init` - Mutex initialization
  - `man pthread_cond_init` - Condition variable initialization
  - `man pthread_mutex_lock/unlock` - Mutex operations
  - `man pthread_cond_wait/broadcast` - Condition variable operations

- **Standard C Library:**
  - `man malloc` - Memory allocation
  - `man free` - Memory deallocation
  - `man usleep` - Microsecond sleep
  - `man gettimeofday` - Timestamp retrieval

- **Classic Concurrency Theory:**
  - Coffman's Conditions for deadlock (mutual exclusion, hold and wait, no preemption, circular wait)
  - Earliest Deadline First (EDF) scheduling algorithm
  - Producer-Consumer problem patterns
  - Resource allocation strategies

### AI Usage

AI was utilized during the project development for:

> **Learning pthread functions**: Understanding the complete pthread API, including advanced features like condition variable broadcasting and mutex-protected queues

## Blocking Cases Handled

### 1. Deadlock Prevention

**Issue addressed:** Multiple coders waiting for dongles in circular dependency

**Solution implemented:**
- **Fixed lock ordering**: Dongles are always locked in ascending ID order when acquiring multiple resources
- **Atomic queue operations**: Dongle availability checks and allocations are performed atomically under `m_queue` mutex
- **Timeout through burnout**: The burnout mechanic provides an implicit timeout mechanism

**Coffman's Conditions mitigation:**
- ✓ **Mutual Exclusion**: Maintained (dongles must be exclusively held)
- ✗ **Hold and Wait**: Partially broken through atomic queue operations and fixed ordering
- ✗ **No Preemption**: Coders can be "preempted" by burnout detection
- ✗ **Circular Wait**: Prevented through consistent lock ordering and EDF scheduling

### 2. Starvation Prevention

**Issue addressed:** Coders with long burnout deadlines starving for dongle access

**Solutions:**
- **EDF Scheduling**: Coders closest to burnout are prioritized in the queue, ensuring urgent work completes first
- **Broadcast notifications**: When dongles are released, ALL waiting coders are notified (`pthread_cond_broadcast`), preventing indefinite waits
- **Queue fairness**: Both FIFO and EDF maintain strict queue discipline for deterministic behavior

### 3. Cooldown Handling

**Issue addressed:** Dongles requiring time between uses must not allow consecutive rapid acquisitions

**Solution implemented:**
- **Timestamp tracking**: Each dongle records `last_use_time` protected by its individual mutex
- **Cooldown enforcement**: `wait_dongles_cooldown()` calculates remaining cooldown and sleeps if necessary
- **Precise calculation**: `usleep()` ensures microsecond-level accuracy without busy-waiting

### 4. Precise Burnout Detection

**Issue addressed:** Race condition between burnout check and compilation start

**Solution implemented:**
- **Atomic time calculation**: `time_left_to_burnout()` reads `last_compile_time` under coder mutex lock
- **Monitor thread scanning**: Monitor continuously checks all coders at high frequency
- **Immediate action**: Burned-out coders are logged and removed from simulation atomically
- **Critical section protection**: Burnout detection occurs under the coder's mutex to prevent TOCTOU bugs

### 5. Log Serialization

**Issue addressed:** Multiple threads writing to stdout simultaneously causes garbled output

**Solution implemented:**
- **Log mutex**: Single `m_log` mutex protects all output operations
- **Atomic writes**: Each `log_action()` call acquires the lock, writes one complete line, then releases
- **Format consistency**: Every log line is guaranteed to be a complete, uninterrupted unit

Example race condition prevented:
```
Without mutex: "11 coder 11 has20 taken coder 220 has taken" (interleaved)
With mutex:    "11 coder 1 has taken\n20 coder 2 has taken\n" (serialized)
```

## Thread Synchronization Mechanisms

### Synchronization Primitives Used

#### 1. `pthread_mutex_t` - Mutual Exclusion Locks

**Global simulation mutexes:**

- **`m_queue`**: Protects the dongle allocation queue and `dongles_availables` counter
  - Used in: Coder registration, dongle acquisition, queue operations
  - Prevents: Multiple coders modifying the queue simultaneously
  
- **`m_log`**: Serializes all logging output
  - Used in: Every `log_action()` call
  - Prevents: Garbled console output from concurrent threads

- **`m_state`**: Protects simulation state (`SIM_WAITING`, `SIM_RUNNING`, `SIM_FAIL`)
  - Used in: State transitions, coder startup synchronization
  - Prevents: Race conditions during simulation initialization

**Per-resource mutexes:**

- **`dongle->mutex`**: Protects individual dongle state (taken status, last_use_time)
  - Allows: Concurrent access to different dongles without contention
  - Prevents: Corrupted dongle state when multiple coders interact with the same dongle

- **`coder->mutex`**: Protects coder state (compilation count, last_compile_time)
  - Used in: `time_left_to_burnout()` for burnout calculation
  - Prevents: Reading corrupted coder state during concurrent updates

#### 2. `pthread_cond_t` - Condition Variables

**Global condition variables:**

- **`c_state`**: Signals when simulation state changes (used for startup)
  ```c
  // In coder threads:
  pthread_cond_wait(&sim->c_state, &sim->m_state);  // Wait for SIM_RUNNING
  ```
  - **Pattern**: Barrier synchronization - all coders wait until simulation starts
  - **Prevents**: Coders acting before initialization completes

- **`c_dongles_availables`**: Notifies when dongles become available
  ```c
  // When dongle released:
  pthread_cond_broadcast(&sim->c_dongles_availables);
  
  // When coder needs dongles:
  while (sim->dongles_availables < 2 || sim->queue[0] != coder)
      pthread_cond_wait(&sim->c_dongles_availables, &sim->m_queue);
  ```
  - **Pattern**: Producer-consumer with priority queue
  - **Broadcast vs Signal**: Uses `broadcast()` to wake all waiting coders, allowing EDF to pick highest priority
  - **Prevents**: Starvation through guaranteed notification

### Thread-Safe Communication Patterns

#### Pattern 1: Atomic Dongle Acquisition

```c
pthread_mutex_lock(&sim->m_queue);
while ((sim->dongles_availables < 2 || sim->queue[0] != coder)
    && is_running(sim))
    pthread_cond_wait(&sim->c_dongles_availables, &sim->m_queue);

// Critical section: Both check and allocation atomic
sim->dongles_availables -= 2;
remove_coder_from_queue(sim, coder);
pthread_mutex_unlock(&sim->m_queue);
```

**Why this prevents race conditions:**
1. Lock acquired before checking `dongles_availables`
2. Condition variable wait atomically releases lock and waits
3. When woken, lock is re-acquired before checking condition
4. Allocation and dequeue are atomic with the check
5. Prevents: Lost wakeups, TOCTOU bugs, double-allocation

#### Pattern 2: Burnout Detection with EDF

```c
// In monitor thread - reads burnout timestamp
t_time time_left = time_left_to_burnout(sim, coder, current_time);
if (time_left <= 0) {
    // Protected burnout logging
    pthread_mutex_lock(&sim->m_log);
    log_action(sim, coder->id, BURNOUT_ACTION);
    pthread_mutex_unlock(&sim->m_log);
}

// In EDF queue insertion
t_time coder_deadline = time_left_to_burnout(sim, coder, time);
// Compare deadlines to insert in priority order
```

**Why this ensures fairness:**
1. All burnout calculations use consistent timestamps
2. Queue ordering determined by burnout proximity
3. Monitor continuously scans all coders
4. Earlier burners are processed first
5. Prevents: Unbounded starvation for urgent coders

#### Pattern 3: Log Serialization

```c
int log_action(t_sim *sim, int coder_id, t_action action) {
    pthread_mutex_lock(&sim->m_log);
    if (!is_running(sim) && action != BURNOUT_ACTION) {
        pthread_mutex_unlock(&sim->m_log);
        return (0);
    }
    printf("%lld %d %s\n", get_timestamp(), coder_id + 1, 
           action_str[action]);
    pthread_mutex_unlock(&sim->m_log);
    return (1);
}
```

**Why this is thread-safe:**
1. Single printf call under lock (no interleaving)
2. Full log line written atomically
3. Lock held for minimal duration
4. Prevents: Garbled timestamps, mixed coder IDs, split log lines

### Race Condition Examples and Prevention

**Race Condition 1: Double Dongle Allocation**

Without protection:
```
Thread A: Check dongles_availables == 2? Yes
Thread B: Check dongles_availables == 2? Yes
Thread A: Decrement to 0, take dongles
Thread B: Decrement to -2, INVALID STATE
```

Solution: Both check and decrement under `m_queue` mutex lock

**Race Condition 2: Corrupted Burnout Timestamp**

Without protection:
```
Monitor thread: Read coder->last_compile_time (high byte) = 1000
Coder thread:   Update coder->last_compile_time = 5000 (while monitor reading)
Monitor thread: Read coder->last_compile_time (low byte) = 0 (CORRUPTED!)
```

Solution: Read `last_compile_time` under `coder->mutex` lock

**Race Condition 3: Simulation State Confusion**

Without protection:
```
Monitor: Check if (state == SIM_RUNNING)? Yes, proceed
Main:    Set state = SIM_FAIL
Monitor: Continue with invalid state assumptions
```

Solution: Both check and use under `m_state` mutex with condition variable

### Scheduling Implementation

#### FIFO Scheduling
- Simple queue insertion at tail
- Fair round-robin access to dongles
- Deterministic behavior

#### EDF (Earliest Deadline First) Scheduling
- Coders closest to burnout inserted with higher priority
- Breakties by coder ID for consistency
- Prevents starvation of urgent coders
- Optimal for real-time constraints

Both algorithms maintain thread-safety through atomic queue operations under `m_queue` mutex.

## Technical Architecture

### Module Organization

- **Coder Management** (`coders/src/coder/`): Thread creation, state transitions, burnout logic
- **Dongle Management** (`coders/src/dongle/`): Resource allocation, scheduling, cooldown
- **Simulation Control** (`coders/src/simulation/`): State machine, initialization, cleanup
- **Monitoring** (`coders/src/monitor/`): Continuous health checks, termination logic
- **Utilities** (`coders/src/utils/`): Logging, timing, argument parsing

### Key Design Decisions

1. **Per-resource mutexes**: Reduces lock contention compared to single global lock
2. **Condition variables for waiting**: Efficient versus polling/busy-waiting
3. **EDF scheduling**: Optimal for deadline-constrained systems
4. **Atomic queue operations**: Prevents inconsistent state in concurrent environment
5. **Monitor thread**: Centralized state management and burnout detection

## Conclusion

Codexion demonstrates comprehensive understanding of multi-threaded programming challenges including deadlock prevention, starvation mitigation, race condition handling, and sophisticated resource scheduling. The project successfully implements real-world concurrency patterns using only POSIX threads without higher-level abstractions.
