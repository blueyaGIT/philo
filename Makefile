NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPFLAGS = -MMD -MP
OBJ_DIR := obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIR := includes
SRC_DIRS := $(shell find ./srcs -type d)
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIR)
vpath %.d $(DEP_DIR)
CFLAGS += -I$(INC_DIR)

# Regular Colors
BLACK       = \033[30m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
MAGENTA     = \033[35m
CYAN        = \033[36m
WHITE       = \033[37m
LIGHT_PINK  = \033[38;5;168m
NC          = \033[0m   # No Color (Reset)

# Other Formatting
UNDERLINE   = \033[4m
REVERSED    = \033[7m
BLINK       = \033[5m
ITALIC      = \033[3m
STRIKE      = \033[9m
CLEAR_LINE  = \033[2K\r

# Source files
SRCS	:=	main.c \
			input.c \

# UTILS
SRCS	+=	error_msg.c \
			free.c \
			ft_atol.c \
			init.c \
			mutex_utils.c \
			philos_utils.c \

# Object files
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

TOTAL_SRCS = $(words $(SRCS))
CURRENT = 0

# Default rule to compile all
all: relink

-include $(OBJS:.o=.d)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL_SRCS)))))
	@printf "$(CLEAR_LINE)$(YELLOW)🚧 Compiling $(PERCENT)%% [$(CURRENT)/$(TOTAL_SRCS)] $(CYAN)$<$(NC) 🚧 "
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# Rule to compile program
relink: $(OBJS)
	@newer=0; \
	if [ ! -f "$(NAME)" ]; then \
		newer=1; \
	else \
		for obj in $(OBJS); do \
			if [ $$obj -nt $(NAME) ]; then \
				newer=1; \
				break; \
			fi; \
		done; \
	fi; \
	if [ $$newer -eq 1 ]; then \
		echo "$(CLEAR_LINE)$(YELLOW)🚧 Building philo 🚧$(NC)"; \
		$(CC) -o $(NAME) $(OBJS); \
		echo "$(CLEAR_LINE)$(GREEN)✅ Done Compiling ✅$(NC)"; \
	else \
		echo "$(CLEAR_LINE)$(GREEN)✅ Skipping relink: $(NAME) is up-to-date ✅$(NC)"; \
	fi

# Clean object files and libraries
clean:
	@rm -rf $(OBJ_DIR)

# Clean all generated files
fclean: clean
	@echo "$(YELLOW)🚧 Cleaning 🚧$(NC)"
	@sleep 0.15
	@printf "$(RED)🧹 Cleaning in Progress 🧹$(NC)\n"
	@sleep 0.15
	@printf "$(YELLOW)🛁 Scrubbing Code 🛁$(NC)\n"
	@sleep 0.15
	@printf "$(CYAN)🧽 Polishing Project 🧽$(NC)\n"
	@sleep 0.15
	@printf "$(MAGENTA)🧴 Tidying Up 🧴$(NC)\n"
	@sleep 0.15
	@printf "$(GREEN)✅ Done Cleaning ✅$(NC)\n"
	@rm -rf $(NAME)

# Rebuild everything
re: fclean all

# Rebuild everything faster
fre:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@make

norm:
	@norminette $(SRC_DIRS) $(INC_DIR)| grep "Error" || printf "$(GREEN)✅ Norme OK ✅ $(NC)\n"

debug: CFLAGS += -g
debug: CFLAGS += -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
debug: CFLAGS += -DDEBUG=1
debug: clean all

# Phony targets
.PHONY: all clean fclean re fre norm debug relink