/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:30:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/31 13:34:37 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clear_tokenizer(void)
{
	char	**list;
	int		*type;
	int		i;

	list = g_data.parser->tokens->list;
	type = g_data.parser->tokens->type;
	i = -1;
	if (list)
	{
		while (list[++i])
			free(list[i]);
		free(list);
	}
	if (type)
		free(type);
	free(g_data.parser->tokens);
}
