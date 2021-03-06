/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/13 15:18:12 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

enum e_lexemas {
	WORD,
	ASSIGN_WORD,
	LESS,
	DLESS,
	GREAT,
	DGREAT,
	AND,
	PARENTHESIS,
	PIPE,
	AND_IF,
	OR_IF
};

/*
** Token and List Structs
*/

typedef struct s_tkn
{
	char			*token;
	int				lexema;
	struct s_tkn	*next;
}	t_tkn;

/*
** Parser Struct
*/

typedef struct s_parser
{
	char		*input;
	t_tkn		*tokens;
}	t_parser;

/*
** Command Struct
*/

typedef struct s_cmd
{
	int				id;
	t_tkn			*commands;
	t_tkn			*redirects;
	int				endpoint;
	int				is_piped;
	char			**exec;
	char			*exec_path;
	char			**envp;
	int				fd_out;
	int				fd_in;
	int				fd_pipe[2];
	int				errnb;
	char			*errfile;
	struct s_cmd	*next;
}	t_cmd;

/*
** Constants definitions
*/

# define METACHAR	"|<>&()"
# define METACHARS	"|<>&() "

/*
** Tokenizer Functions
*/

void		tokenizer(void);
void		token_split(const char *input);
int			is_new_token(const char *input, size_t index, size_t prev);
int			is_assign_word(char *token);

/*
** Token List Utils
*/

t_tkn		*tkn_create(char *token, int flag);
t_tkn		*tkn_dup(t_tkn *original);
t_tkn		*tkn_last(t_tkn *tkn);
void		tkn_remove(t_tkn **list, char *token);
void		tkn_add_back(t_tkn **list, t_tkn *token);
size_t		tkn_len(t_tkn *tkn);
int			lexical_analysis(char *token);

/*
** Syntax Analysis
*/

int			syntax_analysis(void);
void		syntax_word_assignment(void);
int			syntax_pipe_and_or_if(t_tkn *tkn, int pos);
int			syntax_parenthesis(t_tkn *tkn, t_tkn *prev);
int			syntax_io_redirect(t_tkn *tkn);
int			syntax_quote(t_tkn *tkn);
int			syntax_and(t_tkn *tkn);

/*
** Command struc utils
*/

t_cmd		*cmd_create(int id);
void		cmd_add_back(t_cmd *node);
void		cmd_add_front(t_cmd *node);

/*
** Command table
*/

void		swap_token(t_tkn *tkn, char	*new_token);
void		command_table(void);
void		command_expansion(void);
void		command_list(void);
void		tilde_expansion(t_tkn **tkn, int *pos);
void		variable_expansion(t_tkn **tkn, int *pos);
void		quote_expansion(t_tkn **tkn, int *pos, char quote);

#endif