/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_populate_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:45:31 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 13:46:02 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dir	*dir_populate_list(char *directory)
{
	DIR				*dir;
	struct dirent	*dent;
	t_dir			*list;
	char			*filename;
	int				id;

	dir = opendir(directory);
	if (!dir)
		return (NULL);
	id = 0;
	dent = readdir(dir);
	filename = ft_strdup(dent->d_name);
	list = NULL;
	dir_add_sorted(&list, dir_create(filename, id));
	while (1)
	{
		dent = readdir(dir);
		if (!dent)
			break ;
		filename = ft_strdup(dent->d_name);
		if (ft_strncmp(filename, ".", 1))
			dir_add_sorted(&list, dir_create(filename, ++id));
	}
	closedir(dir);
	return (list);
}
