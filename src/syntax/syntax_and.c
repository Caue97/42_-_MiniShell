/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:52:18 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:53:36 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	SYNTAX_AND
**	----------
**	DESCRIPTION
**	Checks the correct grammar of the AND symbol ('&').  
**	PARAMETERS
**	#1. A t_tkn node.
**	RETURN VALUES
**	It returns 1 in case the syntax is correct, and 0 in case an error is found. 
*/

int	syntax_and(t_tkn *tkn)
{
	if (tkn->lexema == AND)
	{
		error(tkn->token, -20, 2);
		return (0);
	}
	return (1);
}
