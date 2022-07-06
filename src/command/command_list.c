/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:43:10 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 16:43:41 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**put_in_list(t_tkn *tkn);

/*	COMMAND_LIST
**	------------
**	DESCRIPTION
**	The command_list function transforms the linked list of command tokens into
**	an double pointer array of strings, ready for execve. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	- 
*/

void	command_list(void)
{
	t_cmd	*cmd;

	cmd = g_data.cmd;
	while (cmd)
	{
		cmd->exec = put_in_list(cmd->commands);
		cmd = cmd->next;
	}
}

static char	**put_in_list(t_tkn *tkn)
{
	size_t	size;
	char	**list;
	int		i;

	size = tkn_len(tkn) + 1;
	list = ft_calloc(sizeof(char *), size);
	i = 0;
	while (tkn)
	{
		list[i] = ft_strdup(tkn->token);
		tkn = tkn->next;
		i++;
	}
	return (list);
}
