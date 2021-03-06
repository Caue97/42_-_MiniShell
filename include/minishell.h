/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/13 15:16:22 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>

# include "../libft/include/libft.h"
# include "hashmap.h"
# include "colors.h"
# include "executables.h"
# include "parser.h"

/*
** Struct definition
*/

typedef struct s_minishell {
	t_hashtable	*environ;
	t_parser	*parser;
	t_cmd		*cmd;
	int			exit_code;
}	t_minishell;

/*
** Environment & Local tables enum definition
*/

enum e_type {
	ENV,
	LOCAL
};

/*
**	Global variable for session data
*/

extern t_minishell	g_data;

/*
** Initialization
*/

void		init_minishell(char **envp);
t_parser	*init_parser(void);
t_tkn		*init_tkn(void);

/*
** System
*/

void		open_terminal(void);
void		change_input_signals(void);

/*
** Program exit functions
*/

void		error(char *s, int flag, int code);
void		clear(void);
void		clear_cmd(void);
void		clear_exec_list(char **exec);
void		clear_parser(void);
void		clear_tokens(t_tkn **list);
void		exit_errno(char *errfile, int errnb);

/*
** Prompt
*/

char		*create_prompt(void);

/*
** Environment variable vector utils
*/

void		envp_create(t_cmd *cmd);
void		envp_clear(t_cmd *cmd);
void		envp_swap(t_cmd *cmd);
size_t		envp_length(char **envp);

#endif