/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:51:33 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/31 14:59:55 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*start_token(char **command)
{
	t_list	*comlist;
	t_list	*holder_list;
	int		counter;

	counter = 0;
	comlist = new_token(command[counter], WORD);
	printf("First Token - %i\n", comlist->token);
	printf("First Input - %s\n", comlist->input);
	counter++;
	while (command[counter] != NULL)
	{
		holder_list = new_token(command[counter], token_type(command[counter]));
		printf("Token - %i\n", holder_list->token);
		printf("Input - %s\n", holder_list->input);
		holder_list->previous = comlist;
		printf("Previous Token - %i\n", holder_list->previous->token);
		printf("Previous Input - %s\n", holder_list->previous->input);
		add_token_to_back(&comlist, holder_list);
		comlist = comlist->next;
		counter++;
	}
	return (find_first_token(comlist));
}

t_list	*new_token(char *command, enum e_tok_type token)
{
	t_list	*new_tlist;

	new_tlist = (t_list *)malloc(sizeof(t_list));
	if (new_tlist)
	{
		new_tlist->next = NULL;
		new_tlist->previous = NULL;
		new_tlist->input = command;
		new_tlist->token = token;
	}
	return (new_tlist);
}

void	add_token_to_back(t_list **comlist, t_list *new_token)
{
	t_list	*current_token;

	if (comlist == NULL)
		return ;
	if (*comlist == NULL)
	{
		*comlist = new_token;
		return ;
	}
	current_token = find_last_token(*comlist);
	current_token->next = new_token;
}

t_list	*find_last_token(t_list *comlist)
{
	if (comlist == NULL)
		return (NULL);
	while (comlist->next != NULL)
	{
		comlist = comlist->next;
	}
	return (comlist);
}

t_list	*find_first_token(t_list *comlist)
{
	if (comlist == NULL)
		return (NULL);
	while (comlist->previous != NULL)
	{
		comlist = comlist->previous;
	}
	return (comlist);
}
