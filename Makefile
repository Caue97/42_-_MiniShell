# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:07:38 by felcaue-          #+#    #+#              #
#    Updated: 2022/07/13 15:35:04 by felcaue-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
LIBFT			= libft.a

#compilation
CC 				= cc
CF 				= -g -Wall -Wextra -Werror
CFI 			= -I $(INCLUDE)
CREADLINE		= -lreadline

LIBFT_PATH 		= ./libft/
SRC_PATH 		= ./src/
OBJ_PATH		= ./objs_minishell/
INCLUDE 		= ./include/

SRC				= main.c\
				assign_word.c\
				exit.c\
				pwd.c\
				export.c\
				cd.c\
				echo.c\
				env.c\
				set.c\
				unset.c\
				is_builtin.c\
				clear.c\
				clear_cmd.c\
				clear_parser.c\
				clear_tokens.c\
				error.c\
				exit_errno.c\
				init_hashtable.c\
				delete_hashmap.c\
				populate_hashmap.c\
				envp_key_value.c\
				envp_length.c\
				envp_create.c\
				hash_insert.c\
				hash_remove.c\
				hash_export.c\
				hash_substitute.c\
				hash.c\
				key_location.c\
				key_search.c\
				change_signals.c\
				create_prompt.c\
				init_minishell.c\
				init_parser.c\
				open_terminal.c\
				tokenizer.c\
				token_utils.c\
				lexical_analysis.c\
				syntax_analysis.c\
				syntax_pipe_and_or_if.c\
				syntax_parenthesis.c\
				syntax_io_redirect.c\
				syntax_and.c\
				syntax_quote.c\
				syntax_word_assignment.c\
				cmd_create.c\
				cmd_add_back.c\
				cmd_add_front.c\
				tkn_add_back.c\
				tkn_create.c\
				tkn_dup.c\
				tkn_remove.c\
				tkn_len.c\
				tkn_last.c\
				command_table.c\
				command_expansion.c\
				command_list.c\
				tilde_expansion.c\
				variable_expansion.c\
				quote_expansion.c\
				exec_line.c\
				open_pipes.c\
				define_redirects.c\
				exec_command.c\
				exec_commands.c\
				exec_commands_signals.c\
				exec_builtin.c\
				close_fds.c\
				get_path.c\
				get_heredoc.c\
				get_heredoc_signals.c\

VPATH 			:= $(SRC_PATH)\
				$(SRC_PATH)builtins\
				$(SRC_PATH)command\
				$(SRC_PATH)exit\
				$(SRC_PATH)hashmap\
				$(SRC_PATH)syntax\
				$(SRC_PATH)system\
				$(SRC_PATH)tokenizer\
				$(SRC_PATH)utils\
				$(SRC_PATH)execute\

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

#common commands
RM 				= rm -rf

#rules
$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ)
				@printf "\n$(CY)Generating libft...$(RC)\n"
				make -C $(LIBFT_PATH) $(LIBFT)
				@printf "\n$(CY)Generating minishell executable...$(RC)\n"
				$(CC) -g $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft $(CREADLINE)
				@printf "$(GR)Done!$(RC)\n\n"

all:			$(NAME)

re:				fclean all

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ) $(OBJDIR)
				@printf "$(RE)minishell objects removed!$(RC)\n\n"

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
				@printf "$(RE)Executables removed!$(RC)\n\n"

install:		
				sudo apt-get install -y libreadline-dev valgrind
				@printf "$(GR)All dependencies ready!$(RC)\n\n"

leak:							
				valgrind --suppressions=./local.supp --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY:			all clean fclean re bonus rebonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m