/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:46:50 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:47:01 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CLEAR
**	-----
**	DESCRIPTION
**	The clear function will free all structures allocated inside the main global 
**	structure of the program. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	clear(void)
{
	if (g_data.environ)
		delete_hashmap();
	if (g_data.parser)
		clear_parser();
	if (g_data.cmd)
		clear_cmd();
	rl_clear_history();
}
