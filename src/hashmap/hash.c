/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:12:43 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/10 12:17:12 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	HASH
**	----
**	This is an implementation of Daniel J. Bernstein's (also known as djb2) hash
**	function. The idea is to initially set a variable called `hash` to the value
**	5381 and subsequently multiply it by 33 (or (hash << 5) + hash) and add the
**	ASCII value of the current character to it, iterating over the entire word.
**	PARAMETERS
**	#1. The string `key` to be hashed;
**	#2. The size of the hashtable.
**	RETURN VALUES
**	The modulo of hash by the size of the given hashtable.
*/

int	hash(char *key, size_t size)
{
	unsigned long int	hash;
	size_t				i;

	hash = 5381;
	i = 0;
	while (key && key[i])
	{
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}
	return (hash % size);
}
