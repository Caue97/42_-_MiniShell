/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:33:16 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/12 18:33:41 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
*	DESCRIPTION
*	Converts the variadic argument into a single character string, returning it
*	into the holder's 'argument' variable.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	#2. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

void	ft_convert_c(t_format *fmt, t_holder *h)
{
	char	ch;

	ch = (wint_t)va_arg(fmt->ap, wint_t);
	if (!h->width)
		h->width += 1;
	h->argument = (char *)malloc(h->width * sizeof(char));
	if (!h->argument)
		return ;
	ft_memset(h->argument, SPACE, h->width);
	if (h->left_justify == 1)
		h->argument[0] = ch;
	else
		h->argument[h->width - 1] = ch;
	h->len = h->width;
}
