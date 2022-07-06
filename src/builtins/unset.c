/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:04:47 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/01 16:05:19 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_single(char *key, char *value);

int	ft_unset(char **exec)
{
	int		i;

	i = 0;
	while (exec[++i])
		hash_remove(exec[i]);
	return (0);
}

int	ft_set(char **exec)
{
	char	*key;
	char	*value;
	int		i;

	i = -1;
	while (exec[++i])
	{
		key = get_key(exec[i]);
		if (!key)
			continue ;
		value = get_value(exec[i]);
		set_single(key, value);
	}
	return (0);
}

static void	set_single(char *key, char *value)
{
	int		location;

	location = key_location(key);
	if (location == -1)
		hash_insert(key, value, LOCAL);
	else
		hash_substitute(key, value);
}
