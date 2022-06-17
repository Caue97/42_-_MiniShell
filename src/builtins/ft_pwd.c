/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:04:34 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/17 11:43:39 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief get the current working directory object
 *
 * @return char* null terminated and allocated string with the directory path.
 */

char	*get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

/**
 * @brief Prints the current working directory.
 *
 */

void	ft_pwd(void)
{
	char	*pwd;

	pwd = get_pwd();
	if (pwd != NULL)
		printf("%s\n", pwd);
	free(pwd);
}
