/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:06:32 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 18:06:36 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CMD_ADD_BACK
**	------------
**	DESCRIPTION
**	It will add a t_cmd node to the back of a t_cmd list.
**	PARAMETERS
**	#1. The t_cmd node to be added in the back of the t_cmd list in the global 
**	struct.
**	RETURN VALUES
**	-
*/

void	cmd_add_back(t_cmd *node)
{
	t_cmd	*cmd_list;

	cmd_list = g_data.cmd;
	if (!cmd_list)
		g_data.cmd = node;
	else
	{
		while (cmd_list->next)
			cmd_list = cmd_list->next;
		cmd_list->next = node;
	}
}
