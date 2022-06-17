/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:12:23 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/10 12:17:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	if (key_search(ENV, key))
		return (ENV);
	if (key_search(LOCAL, key))
		return (LOCAL);
	return (-1);
}
