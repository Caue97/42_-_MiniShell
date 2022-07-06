/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:34:38 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:34:41 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(void)
{
	t_cmd	*cmd;

	cmd = g_data.cmd;
	while (cmd)
	{
		close_fd(cmd, BOTH);
		cmd = cmd->next;
	}
}

void	close_fd(t_cmd *cmd, int flag)
{
	if ((flag == IN || flag == BOTH) && cmd->fd_in > 2)
		close(cmd->fd_in);
	if ((flag == OUT || flag == BOTH) && cmd->fd_out > 2)
		close(cmd->fd_out);
}
