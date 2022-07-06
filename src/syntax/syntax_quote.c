/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:58:41 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:58:53 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	SYNTAX_QUOTE
**	------------
**	DESCRIPTION
**	Checks the closing marks for the quotation symbols ('\' and \"').  
**	PARAMETERS
**	#1. A t_tkn node.
**	RETURN VALUES
**	It returns 1 in case the syntax is correct, and 0 in case an error is found. 
*/

int	syntax_quote(t_tkn *tkn)
{
	int		flag;
	int		i;

	flag = -1;
	i = 0;
	if (!tkn->next)
	{
		while (tkn->token[i])
		{
			if (flag == -1 && (tkn->token[i] == '\"' || tkn->token[i] == '\''))
				flag = i;
			else if (flag != -1 && tkn->token[i] == tkn->token[flag])
				flag = -1;
			i++;
		}
		if (flag != -1)
		{
			error(NULL, -22, 2);
			return (0);
		}
	}
	return (1);
}
