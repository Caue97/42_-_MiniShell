/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:46:31 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/05 16:06:21 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_data;

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1 && argv)
		error(argv[0], 2, 1);
	init_minishell(envp);
	open_terminal();
	return (0);
}
