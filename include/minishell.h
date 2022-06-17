/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:20 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 18:45:04 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# include "../libft/libft.h"
# include "hashmap.h"
# include "colors.h"
# include "executables.h"
# include "parser.h"

/*
** Struct definition
*/

typedef struct s_minishell {
	t_hashtable	*vars[2];
	t_parser	*parser;
	int			exit_code;
	t_list		*c_list;
}	t_minishell;

/*
** Environment & Local tables enum definition
*/

enum e_type {
	ENV,
	LOCAL,
	BOTH
};

/*
**	Global variable for session data
*/

extern t_minishell	g_data;

/*
** System
*/

void		open_terminal(void);
void		error(char *token, int flag, int code);
void		change_signals(void);
void		exit_minishell(void);

/*
** Prompt
*/

char		*create_prompt(void);

/*
** Environment
*/

void		envp_to_hashmap(t_hashtable **table, char **variables);
size_t		envp_length(char **envp);
char		*get_key(char *variable);
char		*get_value(char *variable);
char		*get_pwd(void);
void		ft_echo(char *input);
void		execute_builtin(char **input);

/*
** Utilities
*/

void		print_envp_hash(void);

/*
** Built-ins
*/

void		ft_pwd(void);

/* sort_command functions */

void		sort_command(char *input);

char		**ft_split_command(char *text_rec, char space);

void		populate_hashmap(int type, char **variables);

void		delete_hashmap(int type);

int			hash(char *key, size_t size);

void		clear_tokenizer(void);
void		clear_all(void);
void		clear_parser(void);

t_parser	*init_parser(void);

void		init_minishell(char **variables);
void		change_input_signals(void);

void		ft_createsplit_command(char **result, char *string, char space);
size_t		ft_addpart(char **result, char *prev, size_t size, char c);
int			ft_count_quotes(char *text, char space, int counter);
size_t		ft_countparts(char *text, char space);

#endif
