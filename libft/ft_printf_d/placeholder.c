/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:43:44 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/12 18:44:01 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
*	LIBRARY
*	#include <stdio.h>
*	DESCRIPTION
*	The  placeholder() function manages whatever comes after the '%' char in the
*	printf()'s family functions. It calls the initialize() function for the 
*	format struct, as well as the parse() function that will eventually convert
*	the argument passed to the va_list into the holder struct. At the end, it
*	will print to the screen the converted string of the respective argument.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	RETURN VALUES
*	-
*/

void	ft_placeholder(int fd, t_format *fmt)
{
	t_holder	*h;

	fmt->i++;
	h = ft_initialize_holder();
	ft_parse(fmt, h);
	if (h->conversion)
	{
		ft_type_conversion(fmt, h);
		fmt->len += write(fd, h->argument, h->len);
		free(h->argument);
	}
	free(h->prefix);
	free(h);
}
