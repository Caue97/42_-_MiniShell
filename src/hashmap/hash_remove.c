/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:44:47 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/10 12:17:06 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	HASH_REMOVE
**	-----------
**	Removes a variable from the hashtable's correct hashlist.
**	PARAMETERS
**	#1. The hashtable in which to remove the variable from;
**	#2. The variable's key to delete.
**	RETURN VALUES
**	-
*/

void	hash_remove(int type, char *key)
{
	t_hashtable	*table;
	t_hashlist	*last;
	t_hashlist	*tmp;

	table = g_data.vars[type];
	tmp = table->list[hash(key, table->size)];
	last = NULL;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key)))
		{
			if (!last)
				table->list[hash(key, table->size)] = tmp->next;
			else
				last->next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
		last = tmp;
		tmp = tmp->next;
	}
	return ;
}
