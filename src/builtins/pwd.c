/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:04:34 by elraira-          #+#    #+#             */
/*   Updated: 2022/07/01 15:23:01 by felcaue-         ###   ########.fr       */
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

int	ft_pwd(void)
{
	char	*pwd;

	pwd = get_pwd();
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
