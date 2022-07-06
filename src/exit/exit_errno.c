/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errno.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:49:06 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/05 17:49:14 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_errno(char *errfile, int errnb)
{
	if (errnb == EACCES)
		error(errfile, -50, 126);
	else if (errnb == ENOENT)
		error(errfile, -51, 127);
	else
		error(errfile, -5, 127);
}
