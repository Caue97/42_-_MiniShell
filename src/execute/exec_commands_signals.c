/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands_signals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:37:52 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:38:03 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	quit_process(int signal);
static void	interrupt_process(int signal);
static void	parent_sig(int signal);

/*	EXEC_COMMANDS_SIGNALS
**	---------------------
**	DESCRIPTION
**	It changes the default signals received by specific shortcuts when executing
**	the exec_commands function, to avoid that these signals will respond to the
**	parent shell, instead of the current. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	exec_commands_child_signals(void)
{
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
}

static void	interrupt_process(int signal)
{
	(void)signal;
	error(NULL, 0, 130);
}

static void	quit_process(int signal)
{
	(void)signal;
	error(NULL, 0, 131);
}

void	exec_commands_parent_signals(void)
{
	signal(SIGQUIT, parent_sig);
	signal(SIGINT, parent_sig);
}

static void	parent_sig(int signal)
{
	if (signal == SIGQUIT)
		error(NULL, -53, 131);
	if (signal == SIGINT)
		error(NULL, -54, 130);
}
