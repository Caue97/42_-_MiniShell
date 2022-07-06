/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:16:16 by felcaue-          #+#    #+#             */
/*   Updated: 2022/07/06 18:16:49 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	-
*	DESCRIPTION
*	The strndup() function allocates sufficient memory for a copy of the n first 
*	elements of the string s1, does the copy, and returns a pointer to it.
*	PARAMETERS
*	#1. The string to duplicate.
*	#2. The size of the new string.
*	RETURN VALUES
*	The strdup() function returns the pointer to the copy of s1.
*/

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*ptr;

	if (!size)
		return (NULL);
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
