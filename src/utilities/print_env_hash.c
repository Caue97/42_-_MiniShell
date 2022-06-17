/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:02:40 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/12 10:11:27 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../../include/minishell.h"

void	print_envp_hash(void)
{
	t_hashlist	*list;
	size_t		i;

	// i = -1;
	// while (envp[++i])
	// 	printf("%s\n", envp[i]);
	// printf("\n\n");
	printf("There are a total of %li variables\n\n", g_data.envp->count);
	i = -1;
	while (++i < g_data.envp->size)
	{
		list = g_data.envp->list[i];
		while (list)
		{
			printf("%s=%s in index %li\n", list->key, list->value, i);
			list = list->next;
		}
	}
}
 */
