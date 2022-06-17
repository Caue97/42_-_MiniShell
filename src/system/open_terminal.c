/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:34 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/09 18:17:43 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	open_terminal(void)
{
	char	*input;
	char	*prompt;

	while (1)
	{
		prompt = create_prompt();
		change_input_signals();
		input = readline(prompt);
		if (!input)
		{
			printf("exit\n");
			exit_minishell();
		}
		free(prompt);
		add_history(input);
		execute_builtin(&input);
		sort_command(input);
		
		if (input)
			free(input);
	}
}
