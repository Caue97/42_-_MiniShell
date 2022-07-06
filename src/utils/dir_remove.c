/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:46:32 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 13:46:44 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dir_remove(t_dir **list, int id)
{
	t_dir	*prev;
	t_dir	*curr;

	prev = NULL;
	curr = *list;
	while (curr)
	{
		if (curr->id == id)
		{
			if (!prev)
				*list = curr->next;
			else
				prev->next = curr->next;
			free(curr->file);
			free(curr);
			return ;
		}
		curr = curr->next;
	}
}
