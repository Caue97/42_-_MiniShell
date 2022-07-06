/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:35:36 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 16:35:48 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	INIT_MINISHELL
**	--------------
**	DESCRIPTION
**	This function will first initialize the global structure with the envp 
**	parameter's list (converted into a hashtable), and point all structures that
**	will be used to NULL.
**	PARAMETERS
**	#1. The environment variables list taken from the parent shell.
**	RETURN VALUES
**	-
*/

void	init_minishell(char **envp)
{
	g_data.environ = init_hashtable();
	populate_hashmap(envp);
	envp_create();
	g_data.parser = NULL;
	g_data.cmd = NULL;
	g_data.exit_code = 0;
}
