/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:10:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/17 11:43:33 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* "echo" is a fundamental command found in most operating systems that offer a
command line. It is frequently used in scripts, batch files, and as part of
individual commands; anywhere you may need to insert text. Many command shells
such as bash, ksh and csh implement echo as a built-in command.

Options
-n	Do not output a trailing newline.

*/

void	ft_echo(char *input)
{
	char	*ends;

	ends = "\n";
	if (*input && !ft_strcmp(input, "-n"))
		ends = "\0";
	while (*input)
	{
		printf("%s", input);
		input++;
	}
	printf("%s", ends);
}
