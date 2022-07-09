/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:43:05 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/09 19:56:32 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*path_setup(t_cmd *cmd);
static char	**create_path_list(void);
static void	free_path_list(char **path);

char	*get_path(t_cmd *cmd)
{
	char	*path;

	if (!*cmd->exec)
		return (NULL);
	if (is_builtin(cmd))
		path = ft_strdup(cmd->exec[0]);
	else
	{
		if (ft_strchr(cmd->exec[0], '/') != NULL)
			path = ft_strdup(cmd->exec[0]);
		else
			path = path_setup(cmd);
		if (!path)
		{
			if (key_location("PATH"))
				error(cmd->exec[0], -51, 127);
			else
				error(cmd->exec[0], -5, 127);
		}
	}
	return (path);
}

static char	*path_setup(t_cmd *cmd)
{
	char	**path_list;
	char	*curr_path;
	char	*path;
	int		i;

	path = NULL;
	path_list = create_path_list();
	if (path_list)
	{
		i = -1;
		while (path_list[++i])
		{
			curr_path = ft_strnjoin(3, path_list[i], "/", cmd->exec[0]);
			if (access(curr_path, F_OK) == 0)
			{
				path = curr_path;
				break ;
			}
			free(curr_path);
		}
		free_path_list(path_list);
	}
	if (!path && !access(cmd->exec[0], F_OK | X_OK))
		path = ft_strdup(cmd->exec[0]);
	return (path);
}

static char	**create_path_list(void)
{
	char	**path;
	char	*temp;

	path = NULL;
	temp = key_search("PATH");
	if (temp)
		path = ft_split(temp, ':');
	return (path);
}

static void	free_path_list(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}
