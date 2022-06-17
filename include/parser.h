/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/31 13:40:10 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/* 
	WORD,				string, ex: echo "WORD", nome de arquivos para redirecionamento
	ASSIGNMENT_WORD,	option (-n)
	OR_IF,				||
	LESS,				<
	DLESS,				<<
	GREAT,				>
	DGREAT,				>>
	AND_IF,				&&
	LBRACE,				(
	RBRACE,				)
	PIPE				|
*/
enum e_tok_type {
	WORD,
	ASSIGNMENT_WORD,
	OR_IF,
	LESS,
	DLESS,
	GREAT,
	DGREAT,
	AND_IF,
	LBRACE,
	RBRACE,
	PIPE
};

typedef struct s_tokens
{
	char		**list;
	int			*type;
	size_t		count;
}	t_tokens;

typedef struct s_parser
{
	char		*input;
	t_tokens	*tokens;
}	t_parser;

/* 
	input = string
	token = token_type
	next = ponteiro para o próximo nó
	previous = ponteiro para nó anterior

 */
typedef struct s_list
{
	char				*input;
	enum e_tok_type		token;
	struct s_list		*next;
	struct s_list		*previous;
}	t_list;

t_list	*start_token(char **command);

t_list	*new_token(char *command, enum e_tok_type token);
void	add_token_to_back(t_list **comlist, t_list *new_token);
t_list	*find_last_token(t_list *comlist);
t_list	*find_first_token(t_list *comlist);

int		token_type(char *command_part);

#endif
