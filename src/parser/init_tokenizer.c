/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:41:06 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/31 13:34:11 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_tokens	*init_tokenizer(void)
{
	t_tokens	*tokens;

	tokens = malloc(sizeof(t_tokens));
	if (tokens != NULL)
	{
		tokens->list = NULL;
		tokens->type = NULL;
	}
	return (tokens);
}
