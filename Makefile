GREEN = \033[32m
BLUE = \033[34m
YELLOW = \e[0;33m
RESET = \033[0m

NAME			=	minishell
LIBFT			=	libft.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CINC			=	-I $(INCLUDE_PATH)
CREAD			=	-lreadline

LIBFT_PATH		=	./libft/
SRCS_PATH		=	./src/
OBJS_PATH		=	./objs_minishell/
INCLUDE_PATH	=	./include/

SRCS	=	main.c \
			ft_pwd.c \
			ft_echo.c \
			hash_insert.c \
			envp_key_value.c \
			envp_length.c \
			print_env_hash.c \
			open_terminal.c \
			change_signals.c \
			create_hashmap.c \
			print_hashmap.c \
			error.c \
			create_prompt.c \
			receive_command.c \
			split_command.c \
			populate_hashmap.c \
			delete_hashmap.c \
			hash.c \
			init_parser.c \
			clear_parser.c \
			init_tokenizer.c \
			clear_tokenizer.c \
			clear_all.c \
			exit_minishell.c \
			tokenizer.c \
			list_utils.c

VPATH 		:=	$(SRCS_PATH)\
				$(SRCS_PATH)builtins\
				$(SRCS_PATH)executable\
				$(SRCS_PATH)hashmap\
				$(SRCS_PATH)system\
				$(SRCS_PATH)parser\
				$(SRCS_PATH)utilities\

OBJS			=	$(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))

$(OBJS_PATH)%.o: %.c
				@mkdir -p $(OBJS_PATH)
				@$(CC) $(CFLAGS) $(CINC) -c $< -o $@

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo "$(BLUE)Object files generated!$(RESET)"
			@echo "$(YELLOW)Compiling libft...$(RESET)"
			@$(MAKE) -sC $(LIBFT_PATH) $(LIBFT)
			@$(CC) $(CFLAGS) $(CINC) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft $(CREAD)
			@echo "$(GREEN)Minishell is ready to run! :)$(RESET)"

install:
			sudo apt-get install libreadline-dev
			@echo"$(GREEN)Readline ready!$(RESET)"

clean:
		@make -sC $(LIBFT_PATH) clean
		@rm -rf $(OBJS_PATH)

fclean:	clean
		@make -sC $(LIBFT_PATH) fclean
		@rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
