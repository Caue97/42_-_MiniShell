/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:07:17 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 18:07:20 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_add_front(t_cmd *node)
{
	t_cmd	*cmd_list;
	t_cmd	*tmp;

	cmd_list = g_data.cmd;
	if (!cmd_list)
		g_data.cmd = node;
	else
	{
		tmp = cmd_list;
		g_data.cmd = node;
		g_data.cmd->next = tmp;
	}
}
