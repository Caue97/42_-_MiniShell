/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:56:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/01 16:48:22 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	ENVP_LENGTH
**	-----------
**	DESCRIPTION
**	Gets the length of the environment variables' list. 
**	PARAMETERS
**	#1. The environment variables' list.
**	RETURN VALUES
**	The size_t number correspondent to the list's length.
*/

size_t	envp_length(void)
{
	t_hashtable	*table;
	t_hashlist	*list;
	size_t		i;
	size_t		len;

	i = 0;
	table = g_data.environ;
	list = NULL;
	while (i < table->size)
	{
		list = table->list[i];
		while (list)
		{
			if (list->att == ENV)
				len++;
			list = list->next;
		}
		i++;
	}
	return (len);
}
