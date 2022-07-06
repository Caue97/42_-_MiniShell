/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_substitute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:23:02 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/01 17:00:14 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	HASH_SUBSTITUTE
**	---------------
**	Substitute a new variable at the end of the hashtable's correct hashlist. 
**	PARAMETERS
**	#1. The hashtable ID from which to insert the new variable;
**	#2. The hashtable in which to insert the new variable;
**	#3. The variable's key. 
**	RETURN VALUES
**	-
*/

void	hash_substitute(char *key, char *value)
{
	t_hashtable	*table;
	t_hashlist	*list;
	char		*swap;
	int			index;

	table = g_data.environ;
	index = hash(key, table->size);
	list = table->list[index];
	while (ft_strncmp(list->key, key, ft_strlen(key)))
		list = list->next;
	swap = list->value;
	list->value = ft_strdup(value);
	free(swap);
	free(key);
	free(value);
}
