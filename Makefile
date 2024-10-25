# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 12:30:35 by daeunki2          #+#    #+#              #
#    Updated: 2024/10/25 13:16:57 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Text colors
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# Bold text colors
BOLD_BLACK = \033[1;30m
BOLD_RED = \033[1;31m
BOLD_GREEN = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE = \033[1;34m
BOLD_MAGENTA = \033[1;35m
BOLD_CYAN = \033[1;36m
BOLD_WHITE = \033[1;37m

# Reset color
RESET = \033[0m

# Principals variable needed
NAME = minishell
CC = gcc

# Adding libft directory
LIBFT_DIR = ./includes/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Adding builtins directory path
SRCS_DIRECTORY = ./sources/
# sources directory
EXEC_DIR = ./sources/execution/
EXPANSION_DIR = ./sources/expansion/
PARSING_DIR = ./sources/parsing/
SIGNAL_DIR = ./sources/signal/
TOKEN_DIR = ./sources/tokenization/
OBJ_DIR = ./obj/

OBJS = $(patsubst $(SRCS_DIRECTORY)%.c, $(OBJ_DIR)%.o, $(SRCS))

SRCS =	$(PARSING_DIR)parser.c \
			$(PARSING_DIR)token_check.c \
			$(SIGNAL_DIR)signal.c \
			$(SIGNAL_DIR)signal_heredoc.c \
			$(SRCS_DIRECTORY)main.c \
			$(SRCS_DIRECTORY)printer.c \
			$(SRCS_DIRECTORY)debug.c \
			$(EXPANSION_DIR)find_param.c \
			$(EXPANSION_DIR)assign_quotes.c \
			$(EXPANSION_DIR)file_redir.c \
			$(EXPANSION_DIR)file_redir_utils.c \
			$(EXPANSION_DIR)clear.c \
			$(EXPANSION_DIR)expander.c \
			$(EXPANSION_DIR)expansion_utils.c \
			$(EXPANSION_DIR)jobs.c \
			$(EXPANSION_DIR)lexemes.c \
			$(EXPANSION_DIR)replace.c \
			$(EXPANSION_DIR)token_conversion1.c \
			$(EXPANSION_DIR)token_conversion2.c \
			$(EXEC_DIR)exec_utils1.c \
			$(EXEC_DIR)exec_utils2.c \
			$(EXEC_DIR)exec_free.c \
			$(EXEC_DIR)execution.c \
			$(TOKEN_DIR)create_tokens.c \
			$(TOKEN_DIR)token_substr_len.c \
			$(TOKEN_DIR)token_utils.c \
			$(SRCS_DIRECTORY)builtins/echo/echo.c \
			$(SRCS_DIRECTORY)builtins/env/env.c \
			$(SRCS_DIRECTORY)builtins/exit/exit.c\
			$(SRCS_DIRECTORY)builtins/exit/exit_utils.c\
			$(SRCS_DIRECTORY)builtins/export/export.c \
			$(SRCS_DIRECTORY)builtins/export/export_unset.c \
			$(SRCS_DIRECTORY)builtins/export/export_copy.c \
			$(SRCS_DIRECTORY)builtins/export/export_utils.c \
			$(SRCS_DIRECTORY)builtins/export/sort_env.c \
			$(SRCS_DIRECTORY)builtins/pwd/pwd.c\
			$(SRCS_DIRECTORY)builtins/unset/unset.c \
			$(SRCS_DIRECTORY)builtins/cd/cd.c \
			$(SRCS_DIRECTORY)builtins/cd/cd_paths.c \
			$(SRCS_DIRECTORY)builtins/cd/cd_utils.c \
			$(SRCS_DIRECTORY)builtins/cd/cd_error.c \
			$(SRCS_DIRECTORY)env_var.c \

CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I./includes -g3
LIBS = -lreadline

$(OBJ_DIR)%.o: $(SRCS_DIRECTORY)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(LIBS)
	@echo "$(BOLD_GREEN)Duckyshell is ready!$(RESET)"
	@echo "$(BOLD_GREEN)-------------------$(RESET)"
	@echo "$(BOLD_GREEN)For usage : $(RED)./minishell$(RESET) $(RESET)"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) -s

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@echo "$(BOLD_MAGENTA)Cleaned libft object file..$(RESET)"
	@echo "$(BOLD_MAGENTA)Cleaned minishell object file..$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean -s
	@echo "$(BOLD_MAGENTA)Cleaned minishell exec file..$(RESET)"
	@echo "$(BOLD_RED)Everything is cleaned !$(RESET)"
	
re: fclean all

norm:
	@echo "$(BLUE)Checking norminette for C files...$(RESET)"
	@norminette $(SRCS) \
	|| { echo "$(RED)Norminette failed$(RESET)"; exit 1; }
	@echo "$(BLUE)Checking norminette for Include...$(RESET)"
	@norminette ./include/philo.h || { echo "$(RED)Norminette failed for header$(RESET)"; exit 1; }
	@echo "$(GREEN)Norm is all good!$(RESET)"

.PHONY: all clean fclean re norm
