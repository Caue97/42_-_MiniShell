/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:47:30 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:47:40 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_error(char *s, int flag);
static void	syntax_error(char *s, int flag);
static void	redirect_error(char *s, int flag);
static void	exit_minishell(void);

/*	ERROR
**	-----
**	DESCRIPTION
**	The error function directs the program to close all memory previously 
**	allocated to the global struct, prints the appropriate error message on 
**	the standard error file descriptor and exits with the correct code, if
**	necessary. 
**	PARAMETERS
**	#1. A token used to indicate the step of execution in which it stopped;
**	#2. A flag to indicate the correct message to print;
**	#3. The exit code in which it will close upon.
**	RETURN VALUES
**	-
*/

void	error(char *s, int flag, int code)
{
	g_data.exit_code = code;
	if (flag < 0 && flag > -20)
		exec_error(s, flag);
	if (flag <= -20 && flag > -50)
		syntax_error(s, flag);
	if (flag <= -50)
		redirect_error(s, flag);
	if (flag == 1)
		dprintf(2, "%s\n", s);
	if (flag == 2)
		dprintf(2, "%s: Invalid number of arguments\n", s);
	if (flag == 3)
		dprintf(2, "\n");
	if (flag >= 0)
		exit_minishell();
}

static void	exec_error(char *s, int flag)
{
	if (flag == -1)
		dprintf(2, "minishell: cd: %s not set\n", s);
	if (flag == -2)
		dprintf(2, "minishell: cd: %s: No such file or directory\n", s);
	if (flag == -3)
		dprintf(2, "minishell: cd: %s not set\n", s);
	if (flag == -4)
		dprintf(2, "minishell: %s: too many arguments\n", s);
	if (flag == -5)
		dprintf(2, "%s: Command not found\n", s);
}

static void	syntax_error(char *s, int flag)
{
	if (flag == -20)
		dprintf(2, "minishell: syntax error near unexpected token `%s'\n", s);
	if (flag == -21)
		dprintf(2, "minishell: syntax error near unexpected token `newline'\n");
	if (flag == -22)
		dprintf(2, "minishell: quote missing\n");
	if (flag == -23)
		dprintf(2, "minishell: closing parenthesis missing\n");
}

static void	redirect_error(char *s, int flag)
{
	if (flag == -50)
		dprintf(2, "minishell: %s: Permission denied\n", s);
	if (flag == -51)
		dprintf(2, "minishell: %s: No such file or directory\n", s);
	if (flag == -52)
		dprintf(2, "minishell: warning: here-document delimited by end-of-file (wanted `%s')\n", s);
	if (flag == -53)
		dprintf(2, "Quit\n");
	if (flag == -54)
		dprintf(2, "\n");
}

static void	exit_minishell(void)
{
	clear();
	exit(g_data.exit_code);
}