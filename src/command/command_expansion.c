/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:41:37 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/09 20:01:42 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	token_expansion(t_tkn **tkn);
static void	expand_redirects(t_cmd *cmd);
//static int	is_wildcard_expandable(t_tkn *tkn);

/*	COMMAND_EXPANSION
**	-----------------
**	DESCRIPTION
**	This function will alterate the t_tkn list nodes in place according to
**	specific expansion rules of shell's grammar. The expansion rules include:
**	tilde expansion according to the HOME environment variable, variable
**	expansion according to the environment and local variables (prompted by '$')
**	and quotation expansion, both happening upon start and closing marks.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	command_expansion(void)
{
	t_cmd	*cmd;
	t_tkn	*tkn;

	cmd = g_data.cmd;
	while (cmd)
	{
		tkn = cmd->commands;
		while (tkn)
		{
			token_expansion(&tkn);
			tkn = tkn->next;
		}
		expand_redirects(cmd);
		cmd = cmd->next;
	}
}

static void	expand_redirects(t_cmd *cmd)
{
	t_tkn	*tkn;

	tkn = cmd->redirects;
	while (tkn)
	{
		if (ft_strncmp(tkn->token, "<<", 3))
		{
			tkn = tkn->next;
			token_expansion(&tkn);
		}
		else
			tkn = tkn->next;
		tkn = tkn->next;
	}
}

static void	token_expansion(t_tkn **tkn)
{
	int		pos;

	pos = 0;
	if ((*tkn)->token[pos] == '~')
		tilde_expansion(tkn, &pos);
	while ((*tkn)->token[pos])
	{	
		if ((*tkn)->token[pos] == '$')
			variable_expansion(tkn, &pos);
		else if ((*tkn)->token[pos] == '\'' || (*tkn)->token[pos] == '\"')
			quote_expansion(tkn, &pos, (*tkn)->token[pos]);
		pos++;
	}
}

/*	if (is_wildcard_expandable((*tkn)->token))
		wildcard_expansion(tkn, &pos);

static int	is_wildcard_expandable(t_tkn *tkn)
{
	char	*token;
	int		pos;
	int		is_in;

	token = tkn->token;
	pos = 0;
	is_in = -1;
	while (token[pos] && token[pos] != '/')
	{
		if (token[pos] == '\'' || token[pos] == '\"')
		{
			if (is_in == -1)
				is_in == pos;
			if (is_in >= 0 && token[is_in] == token[pos])
				is_in == -1;
		}
		else if (token[pos] == '*')
			break ;
		pos++;
	}
	if (token[pos] == '*' && is_in == -1)
		return (1);
	return (0);
} */

void	swap_token(t_tkn *tkn, char	*new_token)
{
	free(tkn->token);
	tkn->token = new_token;
}
