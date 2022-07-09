/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_add_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:08:54 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/09 20:03:31 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	go_to_next(t_dir **curr, t_dir **prev);
static void	add_to_begining(t_dir **list, t_dir *item, t_dir *curr);
static void	add_to_middle(t_dir *prev, t_dir *item, t_dir *curr);

void	dir_add_sorted_2(t_dir **list, t_dir *item, t_dir *curr, t_dir *prev)
{
	while (1)
	{
		if (curr && !ft_strncmp(curr->file, "Makefile\0", 9))
			go_to_next(&curr, &prev);
		else if (!ft_strncmp(item->file, "Makefile\0", 9) || \
			(!prev && curr && wordcmp(item->file, curr->file) < 0))
			return (add_to_begining(list, item, curr));
		else if (prev && curr && ((wordcmp(prev->file, item->file) < 0 && \
			wordcmp(item->file, curr->file) < 0) || \
			wordcmp(prev->file, item->file) == 0))
			return (add_to_middle(prev, item, curr));
		else if (!curr)
		{
			prev->next = item;
			break ;
		}
		go_to_next(&curr, &prev);
	}
}

void	dir_add_sorted(t_dir **list, t_dir *item)
{
	t_dir	*curr;
	t_dir	*prev;

	if (!(*list))
		*list = item;
	else
	{
		curr = *list;
		prev = NULL;
		dir_add_sorted_2(list, item, curr, prev);
	}
}

static void	go_to_next(t_dir **curr, t_dir **prev)
{
	*prev = (*prev);
	*curr = (*curr)->next;
}

static void	add_to_begining(t_dir **list, t_dir *item, t_dir *curr)
{
	item->next = curr;
	*list = item;
}

static void	add_to_middle(t_dir *prev, t_dir *item, t_dir *curr)
{
	item->next = curr;
	prev->next = item;
}
