/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:12:10 by elraira-          #+#    #+#             */
/*   Updated: 2022/07/01 17:14:23 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	KEY_SEARCH
**	----------
**	Searches for the value of a given key in a specific hashtable. 
**	PARAMETERS
**	#1. The hashtable to search in,
**	#2. The variable key .
**	RETURN VALUES
**	The value string.
*/

char	*key_search(char *key)
{
	t_hashtable	*table;
	t_hashlist	*tmp;
	int			index;

	table = g_data.environ;
	index = hash(key, table->size);
	tmp = table->list[index];
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
