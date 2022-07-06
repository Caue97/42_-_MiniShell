/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:21:14 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/05 16:14:07 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	reprompt(int signal);

/*	CHANGE_INPUT_SIGNALS
**	--------------------
**	DESCRIPTION
**	It changes the default signals received by specific shortcuts when executing
**	the main minishell function, to avoid that these signals will respond to the
**	parent shell, instead of the current. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	change_input_signals(void)
{
	signal(SIGINT, reprompt);
	signal(SIGQUIT, SIG_IGN);
}

static void	reprompt(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
