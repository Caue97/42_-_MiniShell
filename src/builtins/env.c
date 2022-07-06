/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:57:15 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/01 14:58:08 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_list(t_hashlist *list);

int	ft_env(char **exec)
{
	t_hashtable	*table;
	size_t		i;
	int			ret;

	i = 0;
	table = g_data.environ;
	ret = 127;
	if (!key_search("PATH"))
		error(exec[0], -51, ret);
	else if (!exec[1] || !*exec[1])
		while (i < table->size)
			ret = print_list(table->list[i++]);
	else
		error(exec[1], -51, ret);
	return (ret);
}

static int	print_list(t_hashlist *list)
{
	while (list)
	{
		if (list->att == ENV && list->value)
			printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	return (0);
}
