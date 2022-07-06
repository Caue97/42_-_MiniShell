/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:45:47 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:45:59 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CLEAR_PARSER
**	------------
**	DESCRIPTION
**	The clear_parser function will free the entire t_parser struct inside the 
**	main global structure, clearing the token's list and the input string. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	clear_parser(void)
{
	if (!g_data.parser)
		return ;
	if (g_data.parser->input)
		free(g_data.parser->input);
	if (g_data.parser->tokens)
		clear_tokens(&g_data.parser->tokens);
	free(g_data.parser);
	g_data.parser = NULL;
}
