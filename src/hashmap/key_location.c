/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:12:23 by elraira-          #+#    #+#             */
/*   Updated: 2022/07/01 17:01:47 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	KEY_LOCATION
**	------------
**	Checks which hashtable the variable is stored 
**	PARAMETERS
**	#1. The variable key 
**	RETURN VALUES
**	0 for Environment table, 1 for Local table, or -1 for not found.
*/

int	key_location(char *key)
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
			return (tmp->att);
		tmp = tmp->next;
	}
	return (-1);
}
