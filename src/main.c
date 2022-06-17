/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:46:31 by cado-car          #+#    #+#             */
/*   Updated: 2022/06/16 18:36:02 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_minishell	g_data;

void	init_minishell(char **variables)
{
	g_data.vars[ENV] = create_hashmap(variables);
	g_data.vars[LOCAL] = create_hashmap(NULL);
	if (variables)
		populate_hashmap(ENV, variables);
	g_data.parser = init_parser();
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1 && argv)
		printf("Error! Wrong number of arguments!\n");
	else
	{
		init_minishell(envp);
		print_hashmap(ENV);
		open_terminal();
	}
	return (0);
}
