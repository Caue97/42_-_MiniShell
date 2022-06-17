/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:33:46 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/13 13:34:18 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clear_all(void)
{
	if (g_data.vars[ENV])
		delete_hashmap(ENV);
	if (g_data.vars[LOCAL])
		delete_hashmap(LOCAL);
	if (g_data.parser)
		clear_parser();
	clear_history();
}
