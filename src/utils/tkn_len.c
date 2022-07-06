/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:36:26 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 17:36:38 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_LEN
**	-------
**	DESCRIPTION
**	This function will count the size of a t_tkn list. 
**	PARAMETERS
**	#1. The list to count from. 
**	RETURN VALUES
**	The size_t length of the list.  
*/

size_t	tkn_len(t_tkn *tkn)
{
	size_t	len;

	len = 0;
	while (tkn)
	{
		len++;
		tkn = tkn->next;
	}
	return (len);
}
