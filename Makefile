# Program name
NAME     = codexion

# Style
GREY     = \033[0;30m
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
PURPLE   = \033[0;35m
CYAN     = \033[0;36m
WHITE    = \033[0;37m

BOLD     = \033[1m
UNDER    = \033[4m
REV      = \033[7m
BLINK    = \033[5m

NC       = \033[0;0m
ERASE    = \033[2K\r
ERASE2   = $(ERASE)\033[F$(ERASE)

# Compiler and flags
CC       = cc

DEPFLAGS = -MMD -MP
CFLAGS   = $(DEPFLAGS) -Wall -Wextra -Werror
DEBUG_FLAGS = -g3

BONUS_CFLAGS := $(CFLAGS) -DPRINT_OPERATION=0

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUG_FLAGS)
endif


# Includes
INCLUDES = -I includes/

# Source files (grouped with correct directories)
CODEXION_DIR             = src/

# Mandatory sources (in src/)
CODEXION_MANDATORY			= codexion.c


# Utils sources (in src/utils/)
CODEXION_UTILS_DIR			= src/utils/
CODEXION_UTILS				= 


# Build full paths for all sources
CODEXION_FILE	= $(addprefix $(CODEXION_DIR), $(CODEXION_MANDATORY)) \
					$(addprefix $(CODEXION_UTILS_DIR), $(CODEXION_UTILS)) \
					$(addprefix $(CODEXION_OPERATIONS_DIR), $(CODEXION_OPERATIONS)) \
					$(addprefix $(CODEXION_STRATEGIES_DIR), $(CODEXION_STRATEGIES))


M_FILE  = $(CODEXION_FILE)

# Object files directory
OBJ_DIR   = .obj/
OBJ       = $(M_FILE:%.c=$(OBJ_DIR)%.o)

DEPS      = $(M_FILE:%.c=$(OBJ_DIR)%.d)

# NORMINETTE (use same paths as norm target)
# NORM_RET = $(RED)[ERROR]$(BOLD) Norminette Disable$(NC)
NORM   = $(shell norminette src/ libft/ includes/ | grep -c 'Error!')
ifeq ($(NORM), 0)
  NORM_RET = $(GREEN)[DONE] $(BOLD)$(YELLOW)Norminette.$(NC)
else
  NORM_RET = $(RED)[ERROR] $(BOLD)$(YELLOW)Norminette.$(NC)
endif

COMPILED_FILES := 0

# Pattern rule for object files
$(OBJ_DIR)%.o : %.c
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║       Starting $(YELLOW2)$(NAME)$(YELLOW) compilation...       ║$(NC)";           \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
	@printf "\n$(GREEN)[Compiling] $(NC)$(shell echo $< | sed 's|^src/||')";

# New pattern rule for bonus object files (compile checker sources with BONUS_CFLAGS)
$(OBJ_BONUS_DIR)%.o : %.c
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║         Starting $(YELLOW2)checker$(YELLOW) compilation...       ║$(NC)";       \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@mkdir -p $(dir $@)
	@$(CC) $(BONUS_CFLAGS) -o $@ -c $< $(INCLUDES)
	@printf "\n$(GREEN)[Compiling] $(NC)$(shell echo $< | sed 's|^src/||')";

all : make_libft $(NAME) nothing_to_be_done

nothing_to_be_done:
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║       Nothing to be done for $(YELLOW2)$(NAME)$(YELLOW).       ║$(NC)";           \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)\n";                          \
	fi

$(NAME) : $(LIBFT) $(OBJ)
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║       Starting $(YELLOW2)$(NAME)$(YELLOW) compilation...       ║$(NC)";           \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@echo "\n\n$(GREEN)[Compiling program] $(NC)$(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
# 	@make --no-print-directory end_message

# New rule to build checker executable
checker: $(LIBFT) $(CHECKER_OBJ)
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║         Starting $(YELLOW2)checker$(YELLOW) compilation...       ║$(NC)";       \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@echo "\n\n$(GREEN)[Compiling program] $(NC)checker"
	@$(CC) $(BONUS_CFLAGS) -o checker $(CHECKER_OBJ) $(LIBFT)

# bonus target builds the checker
bonus: checker

make_libft:
	@make --no-print-directory -C $(LIBFTDIR) all

$(LIBFT): make_libft

clean :
	@echo "$(RED)[Removing] $(NC)libft object files"
	@make --no-print-directory -C $(LIBFTDIR) clean
	@echo "$(RED)[Removing] $(NC)object files"
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make --no-print-directory -C $(LIBFTDIR) fclean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)[Removing] $(NC)program $(NAME)"; \
		rm -f $(NAME); \
	fi
	@if [ -f checker ]; then \
		echo "$(RED)[Removing] $(NC)program checker"; \
		rm -f checker; \
	fi
	@if [ -f checker ]; then \
		echo "$(RED)[Removing] $(NC)program checker"; \
		rm -f checker; \
	fi

fcleanp :
	@echo "$(RED)[Removing] $(NC)object files"
	@rm -rf $(OBJ_DIR)
	@if [ -f $(NAME) ]; then \
		echo "$(RED)[Removing] $(NC)program $(NAME)"; \
		rm -f $(NAME); \
	fi

re : fclean
	@make --no-print-directory all

debug: all 

norm:
	@norminette src/ libft/ includes/

bonus:

.PHONY: all clean fclean re make_libft nothing_to_be_done norminette debug bonus checker

-include $(DEPS) $(CHECKER_DEPS)