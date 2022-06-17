/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:41:06 by elraira-          #+#    #+#             */
/*   Updated: 2022/06/06 12:46:48 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_builtin(char **input)
{
	if (!ft_strcmp(*input, "pwd\0"))
		ft_pwd();
	if (!ft_strcmp(*input, "echo\0"))
		ft_echo(*input);
/*	if (!ft_strcmp(*input, "exit\0"))
		//ft_exit(*input);
	if (!ft_strcmp(*input, "cd\0"))
		//ft_cd(path);
	if (!ft_strcmp(*input, "unset\0"))
		ft_unset(*input);
	if (!ft_strcmp(*input, "export\0"))
		ft_export(*input);
	if (!ft_strcmp(*input, "env\0"))
		ft_env(*input); */
}

/* int	is_command(char *command_part)
{
	if (!(ft_strcmp(command_part, "echo\0")))
		return (WORD);
	if (!(ft_strcmp(command_part, "exit\0")))
		return (WORD);
	if (!(ft_strcmp(command_part, "echo\0")))
		return (WORD);
	if (!(ft_strcmp(command_part, "unset\0")))
		return (WORD);
	if (!(ft_strcmp(command_part, "env\0")))
		return (WORD);
	if (!(ft_strcmp(command_part, "export\0")))
		return (WORD);
	if (!(ft_strcmp(command_part, "cd\0")))
		return (WORD);
	if (!(ft_strcmp(command_part, "pwd\0")))
		return (WORD);
	return (NULL);
}*/

int	token_size_1(char *command_part)
{
	if (command_part[0] == '|')
		return (PIPE);
	else if (command_part[0] == '>')
		return (GREAT);
	else if (command_part[0] == '<')
		return (LESS);
	else if (command_part[0] == '(')
		return (LBRACE);
	else if (command_part[0] == ')')
		return (RBRACE);
	else
		return (WORD);
}

int	token_size_2(char *command_part)
{
	if (!ft_strcmp(command_part, "||"))
		return (OR_IF);
	else if (!ft_strcmp(command_part, ">>"))
		return (DGREAT);
	else if (!ft_strcmp(command_part, "<<"))
		return (DLESS);
	else if (!ft_strcmp(command_part, "&&"))
		return (AND_IF);
	else
		return (WORD);
}

int	token_type(char *command_part)
{
	int	holder;

	holder = 0;
	if (ft_strlen(command_part) == 1)
	{
		holder = token_size_1(command_part);
	}
	else if (ft_strlen(command_part) == 2)
	{
		holder = token_size_2(command_part);
	}
	else if (!ft_strcmp(command_part, "-n"))
		return (ASSIGNMENT_WORD);
	else
		return (WORD);
	return (holder);
}
