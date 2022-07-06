/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:08:07 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 17:08:09 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_DUP
**	-------
**	DESCRIPTION
**	This function will duplicate a t_tkn node with next pointer to NULL. 
**	PARAMETERS
**	#1. The original token;
**	RETURN VALUES
**	The allocated (malloc(3)) t_tkn duplicated node.
*/

t_tkn	*tkn_dup(t_tkn *original)
{
	t_tkn	*tkn;

	tkn = malloc(sizeof(t_tkn));
	if (!tkn)
		error(NULL, 0, 12);
	tkn->token = ft_strdup(original->token);
	tkn->lexema = original->lexema;
	tkn->next = NULL;
	return (tkn);
}
