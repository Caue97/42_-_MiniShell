/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hashmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:11:42 by elraira-          #+#    #+#             */
/*   Updated: 2022/06/16 18:38:51 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_table(int type);
static void	print_list(t_hashlist *list);

/*	PRINT_HASHMAP
**	-------------
**	Prints the hashmaps.
**	PARAMETERS
**	#1. The type of the hashmap to print.
**	RETURN VALUES
**	-
*/

void	print_hashmap(int type)
{
	if (type == ENV || type == BOTH)
		print_table(ENV);
	if (type == LOCAL || type == BOTH)
		print_table(LOCAL);
}

static void	print_table(int type)
{
	t_hashtable	*table;
	size_t		i;

	i = 0;
	table = g_data.vars[type];
	while (i < table->size)
		print_list(table->list[i++]);
}

static void	print_list(t_hashlist *list)
{
	while (list)
	{
		printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
}
