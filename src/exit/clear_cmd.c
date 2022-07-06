/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:44:54 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:45:11 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_exec_list(char **exec);

/*	CLEAR_CMD
**	---------
**	DESCRIPTION
**	The clear_cmd function will free the entire t_cmd struct inside the 
**	main global structure, clearing the command and redirect token's list, the 
**	exec array and the exec_path string. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	clear_cmd(void)
{
	t_cmd	*curr;
	t_cmd	*tmp;

	curr = g_data.cmd;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		clear_tokens(&tmp->commands);
		clear_tokens(&tmp->redirects);
		clear_exec_list(tmp->exec);
		if (tmp->exec_path)
			free(tmp->exec_path);
		free(tmp);
	}
	g_data.cmd = NULL;
}

static void	clear_exec_list(char **exec)
{
	int	i;

	if (!exec)
		return ;
	i = -1;
	while (exec[++i])
		free(exec[i]);
	free(exec);
}
