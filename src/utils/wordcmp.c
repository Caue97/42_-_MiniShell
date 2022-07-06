/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:02:29 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 18:03:38 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wordcmp(char *s1, char *s2)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (s1[i] && s2[i])
	{
		result = ft_tolower(s1[i]) - ft_tolower(s2[i]);
		if (result)
			break ;
		i++;
	}
	if (!result)
		result = ft_tolower(s1[i]) - ft_tolower(s2[i]);
	return (result);
}
