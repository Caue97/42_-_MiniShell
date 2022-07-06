/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:27:27 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 18:27:29 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dir_delete(t_dir **list)
{
	t_dir	*dir;
	t_dir	*tmp;

	dir = *list;
	while (dir)
	{
		tmp = dir;
		dir = dir->next;
		free(tmp->file);
		free(tmp);
	}
}
