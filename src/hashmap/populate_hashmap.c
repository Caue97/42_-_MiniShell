/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_hashmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:11:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/10 12:17:22 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	populate_hashmap
**	----------------
**	DESCRIPTION
**	Takes the list of environment variables and, for each one of them, inserts
**	them into the hash table passed.
**	PARAMETERS
**	#1. The type of table to populate,
**	#2. The list of variables passed.
**	RETURN VALUES
**	-
*/

void	populate_hashmap(int type, char **variables)
{
	char		*key;
	char		*value;
	int			i;

	i = 0;
	while (variables[i])
	{
		key = get_key(variables[i]);
		value = get_value(variables[i]);
		hash_insert(type, key, value);
		i++;
	}
}
