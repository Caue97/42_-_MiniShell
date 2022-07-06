/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:58:41 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/01 15:16:22 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numberic(char *param);

int	ft_exit(char **exec)
{
	int	ret;

	ret = 0;
	if (exec[1] && exec[2])
	{
		error("exit", -4, 1);
		return (1);
	}
	if (exec[1] && is_numberic(exec[1]))
	{
		ret = ft_atoi(exec[1]);
		if (ret < 0 || ret > 255)
			ret = 128;
	}
	error("exit", 1, ret);
	return (0);
}

static int	is_numberic(char *param)
{
	int	i;

	i = -1;
	while (param[++i])
	{
		if (!ft_isdigit(param[i]) && param[i] != '+' && param[i] != '-')
			return (0);
	}
	return (1);
}
