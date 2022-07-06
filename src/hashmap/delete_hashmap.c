/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:11:50 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/01 16:38:38 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	list_delete(t_hashlist *node);

/*	DELETE_HASHMAP
**	--------------
**	Deletes the hashtable and all its nodes.
**	PARAMETERS
**	#1. The type of the hashtable to delete.
**	RETURN VALUES
**	-
*/

void	delete_hashmap(void)
{
	t_hashtable	*table;
	size_t		i;

	i = 0;
	table = g_data.environ;
	while (i < table->size)
		list_delete(table->list[i++]);
	free(table->list);
	envp_clear();
	free(table);
}

static void	list_delete(t_hashlist *node)
{
	t_hashlist	*tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node;
		node = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}
