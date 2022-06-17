/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:28:48 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/13 13:37:55 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	ERROR
**	-----
**	DESCRIPTION
**	The error function directs the program to close all memory previously
**	allocated to the global struct, prints the appropriate error message and
**	exits with the correct code.
**	PARAMETERS
**	#1. A token used to indicate the step of execution in which it stopped;
**	#2. A flag to indicate the correct message to print;
**	#3. The exit code in which it will close upon.
**	RETURN VALUES
**	-
*/

void	error(char *token, int flag, int code)
{
	g_data.exit_code = code;
	if (flag == 1)
		printf("%s: Invalid number of arguments\n", token);
	if (flag == 2)
		printf("%s\n", token);
	if (flag == 3)
		printf("Quote missing\n");
	if (flag == -1)
		printf("minishell: cd: %s not set\n", token);
	if (flag == -2)
		printf("minishell: cd: %s: No such file or directory\n", token);
	if (flag >= 0)
		exit_minishell();
}
