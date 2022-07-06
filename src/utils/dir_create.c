/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:18:37 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 18:27:07 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dir	*dir_create(char *file, int id)
{
	t_dir *dir;

	dir = malloc(sizeof(t_dir));
	if (!dir)
		return (NULL);
	dir->id = id;
	dir->file = file;
	dir->next = NULL;
	return (dir);
}
