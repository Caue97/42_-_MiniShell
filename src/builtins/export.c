/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:16:53 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/01 15:17:19 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_single(char *key, char *value);
static void	print_exported(void);

int	ft_export(char **exec)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	if (!exec[1] || !*exec[1])
		print_exported();
	while (exec[++i])
	{
		key = get_key(exec[i]);
		if (!key)
			key = ft_strdup(exec[i]);
		value = get_value(exec[i]);
		export_single(key, value);
	}
	return (0);
}

static void	export_single(char *key, char *value)
{
	int	location;

	location = key_location(key);
	if (location == -1)
		hash_insert(key, value, ENV);
	else if (location == ENV)
		hash_substitute(key, value);
	else
		hash_export(key, ENV);
}

static void	print_exported(void)
{
	t_hashlist	**list;
	t_hashlist	*node;
	size_t		i;

	list = g_data.environ->list;
	i = 0;
	while (i < g_data.environ->size)
	{
		node = list[i];
		while (node)
		{
			if (node->att == ENV)
			{
				if (!node->value)
					printf("declare -x %s\n", node->key);
				else
					printf("declare -x %s=\"%s\"\n", node->key, node->value);
			}
			node = node->next;
		}
		i++;
	}
}