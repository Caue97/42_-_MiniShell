/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:10:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/07/07 16:51:17 by felcaue-         ###   ########.fr       */
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

int	ft_echo(char **exec)
{
	char	*flag;
	int		i;

	flag = NULL;
	i = 1;
	if (exec[i] && *exec[i] == '-')
		flag = &exec[i++][1];
	while (exec[i])
	{
		printf("%s", exec[i++]);
		if (exec[i])
			printf(" ");
	}
	if (ft_strncmp(flag, "n\0", 2))
		printf("\n");
	return (0);
}
