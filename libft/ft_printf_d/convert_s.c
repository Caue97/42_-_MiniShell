/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:38:32 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/12 18:38:39 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
*	DESCRIPTION
*	Converts the variadic argument into a full string, returning it into the 
*	holder's 'argument' variable.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	#2. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

void	ft_convert_s(t_format *fmt, t_holder *h)
{
	char	*s;
	int		len;
	char	*temp;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	len = (int)ft_strlen(s);
	h->argument = (char *)malloc((len + 1) * sizeof(char));
	if (!h->argument)
		return ;
	ft_strlcpy(h->argument, s, len + 1);
	if (h->precision > -1)
	{
		temp = h->argument;
		h->argument = ft_strndup(temp, (size_t)h->precision);
		free(temp);
	}
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, ' ', h->width);
	else
		ft_fill_right_pad(&h->argument, ' ', h->width);
	h->len = ft_strlen(h->argument);
	free(s);
}
