/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:45:48 by cado-car          #+#    #+#             */
/*   Updated: 2022/05/26 15:10:41 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	*init_parser(void)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	if (!parser)
		error(NULL, 0, 12);
	parser->input = NULL;
	parser->tokens = NULL;
	return (parser);
}
