/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:06:15 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 17:06:29 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TKN_CREATE
**	----------
**	DESCRIPTION
**	This function will create a new t_tkn list node. 
**	PARAMETERS
**	#1. The token allocated string;
**	#2. The flag which indicates if the string will pass through the lexical 
**	analysis (0) or not (1).
**	RETURN VALUES
**	The allocated (malloc(3)) t_tkn node. 
*/

t_tkn	*tkn_create(char *token, int flag)
{
	t_tkn	*tkn;

	tkn = malloc(sizeof(t_tkn));
	if (!tkn)
		error(NULL, 0, 12);
	tkn->token = token;
	if (!flag)
		tkn->lexema = lexical_analysis(token);
	else
		tkn->lexema = WORD;
	tkn->next = NULL;
	return (tkn);
}
