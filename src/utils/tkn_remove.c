/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:42:13 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 17:42:16 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_REMOVE
**	-----------
**	Removes a token from the tkn struct. 
**	PARAMETERS
**	#1. The tkn list in which to remove the variable from;
**	#2. The token's string to delete. 
**	RETURN VALUES
**	-
*/

void	tkn_remove(t_tkn **list, char *token)
{
	t_tkn	*tmp;
	t_tkn	*last;

	tmp = *list;
	last = NULL;
	while (tmp)
	{
		if (!ft_strncmp(tmp->token, token, ft_strlen(token)))
		{
			if (!last)
				*list = tmp->next;
			else
				last->next = tmp->next;
			free(tmp->token);
			free(tmp);
		}
		last = tmp;
		tmp = tmp->next;
	}
}
