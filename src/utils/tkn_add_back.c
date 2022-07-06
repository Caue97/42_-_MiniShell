/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:05:07 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 17:05:16 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_ADD_BACK
**	------------
**	DESCRIPTION
**	Add the created t_tkn node to the back of a t_tkn list.  
**	PARAMETERS
**	#1. The t_tkn's list in which to add the node;
**	#2. The node to be added.
**	RETURN VALUES
**	-
*/

void	tkn_add_back(t_tkn **list, t_tkn *token)
{
	t_tkn	*tmp;

	tmp = *list;
	if (!tmp)
		(*list) = token;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = token;
	}
}
