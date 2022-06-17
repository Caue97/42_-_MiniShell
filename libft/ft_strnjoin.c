/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:27:43 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/03 09:28:35 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(int argn, ...)
{
	char	*result;
	char	*buf;
	char	*tmp;
	va_list	argl;
	int		i;

	if (argn == 0)
		return (NULL);
	va_start(argl, argn);
	result = NULL;
	i = -1;
	while (++i < argn)
	{
		buf = va_arg(argl, char *);
		if (i == 0)
			result = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(result, buf);
			free(result);
			result = tmp;
		}
	}
	va_end(argl);
	return (result);
}
