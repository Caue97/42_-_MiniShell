/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_signals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:41:14 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:41:18 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_sig(int signal);

/*	FET_HEREDOC_SIGNAL
**	------------------
**	DESCRIPTION
**	It changes the default signals received by specific shortcuts when executing
**	the get_heredoc function, to avoid that these signals will respond to the
**	parent shell, instead of the current. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	get_heredoc_child_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, child_sig);
}

static void	child_sig(int signal)
{
	(void)signal;
	error(NULL, 3, 130);
}

void	get_heredoc_parent_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}
