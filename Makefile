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
NORM   = $(shell norminette src/ includes/ | grep -c 'Error!')
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

all: $(NAME) nothing_to_be_done

nothing_to_be_done:
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║       Nothing to be done for $(YELLOW2)$(NAME)$(YELLOW).       ║$(NC)";           \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)\n";                          \
	fi

$(NAME) : $(OBJ)
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║       Starting $(YELLOW2)$(NAME)$(YELLOW) compilation...       ║$(NC)";           \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@echo "\n\n$(GREEN)[Compiling program] $(NC)$(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	@echo "$(RED)[Removing] $(NC)object files"
	@rm -rf $(OBJ_DIR)

fclean : clean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)[Removing] $(NC)program $(NAME)"; \
		rm -f $(NAME); \
	fi

re: fclean all

debug: all

norm:
	@norminette src/

bonus:

.PHONY: all clean fclean re nothing_to_be_done norminette debug

-include $(DEPS)