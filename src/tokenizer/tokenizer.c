/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:03:54 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 18:04:04 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_part(const char *input, size_t size);

/*	TOKENIZER
**	---------
**	DESCRIPTION
**	The tokenizer function will split the original input line into "tokens"
**	(meaninfull words), the first step to properly "understand" what the user
**	is trying to accomplish with the command. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	tokenizer(void)
{
	char	*input;
	size_t	i;
	size_t	prev;
	size_t	next;
	size_t	size;

	input = g_data.parser->input;
	i = 0;
	prev = i;
	next = i;
	size = 0;
	while (1)
	{
		if (is_new_token(input, i, prev))
			next = i;
		size = next - prev;
		if (size > 0)
			add_part(&input[prev], size);
		if (!input[i])
			break ;
		prev = next;
		i++;
	}
}

static void	add_part(const char *input, size_t size)
{
	t_tkn	*tkn;
	char	*token;

	while (*input == ' ')
	{
		size--;
		input++;
	}
	if (!size || !(*input))
		return ;
	token = ft_strndup(input, size);
	tkn = tkn_create(token, 0);
	tkn_add_back(&g_data.parser->tokens, tkn);
}
