/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:36:15 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:36:29 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin_in_parent(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "cd\0", 3))
		g_data.exit_code = ft_cd(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "export\0", 7))
		g_data.exit_code = ft_export(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "unset\0", 6))
		g_data.exit_code = ft_unset(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "exit\0", 5))
		g_data.exit_code = ft_exit(cmd->exec);
	else if (cmd->commands->lexema == ASSIGN_WORD)
		ft_set(cmd->exec);
	envp_swap();
}

void	exec_builtin_in_child(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "env\0", 4))
		g_data.exit_code = ft_env(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "echo\0", 5))
		g_data.exit_code = ft_echo(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "pwd\0", 4))
		g_data.exit_code = ft_pwd();
}