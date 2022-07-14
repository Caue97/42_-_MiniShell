/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:00:16 by cado-car          #+#    #+#             */
/*   Updated: 2022/07/13 16:23:00 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_current_folder(void);

/*	CREATE_PROMPT
**	-------------
**	DESCRIPTION
**	The create_prompt function will malloc(3) a string properly formatted that
**	will describe the minishell program and the current folder's path. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

char	*create_prompt(void)
{
	char	*name;
	char	*folder;
	char	*end;
	char	*prompt;

	name = ft_strdup("🐚🐚🐚 MINISHELL");
	folder = get_current_folder();
	end = ft_strdup(" $ ");
	prompt = ft_strnjoin(9, ESC_BOLD_PURPLE, name, ESC_BOLD_BLACK, ":", \
		ESC_BOLD_RED, folder, ESC_BOLD_BLACK, end, ESC_RESET_COLOR);
	free(name);
	free(folder);
	free(end);
	return (prompt);
}

static char	*get_current_folder(void)
{
	char	*path;
	char	*folder;
	char	*result;

	path = get_pwd();
	folder = ft_strrchr(path, '/');
	result = ft_strjoin(&folder[1], "/");
	free(path);
	return (result);
}
