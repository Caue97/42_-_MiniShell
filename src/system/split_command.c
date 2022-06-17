/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:35:56 by felcaue-          #+#    #+#             */
/*   Updated: 2022/05/12 19:25:56 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_count_quotes(char *text, char space, int counter)
{
	if (text[counter] == 34)
	{
		counter++;
		while (text[counter] != '\0')
		{
			if (text[counter] == 34 && text[counter + 1] == space)
				break ;
			counter++;
		}
	}
	if (text[counter] == 39)
	{
		counter++;
		while (text[counter] != '\0')
		{
			if (text[counter] == 39 && text[counter + 1] == space)
				break ;
			counter++;
		}
	}
	return (counter);
}

size_t	ft_countparts(char *text, char space)
{
	size_t	count;
	int		counter;

	if (!*text)
		return (0);
	counter = 0;
	count = 0;
	while (text[counter])
	{
		while (text[counter] == space)
			counter++;
		if (text[counter])
			count++;
		counter = ft_count_quotes(text, space, counter);
		while (text[counter] != space && text[counter] != '\0')
		{
			counter++;
		}
	}
	printf("%li\n", count);
	return (count);
}

char	**ft_split_command(char *text_rec, char space)
{
	char	**lst;

	lst = (char **)malloc((ft_countparts(text_rec, space) + 1) \
			* sizeof(char *));
	if (!text_rec || !lst)
		return (0);
	ft_createsplit_command(lst, text_rec, space);
	return (lst);
}

void	ft_createsplit_command(char **result, char *string, char space)
{
	size_t	count_char;
	size_t	count_d;
	size_t	size;
	size_t	prev;
	size_t	next;

	count_char = 0;
	count_d = 0;
	prev = count_char;
	next = count_char;
	while (1)
	{
		if (string[count_char] == 34 || string[count_char] == 39)
			count_char = ft_count_quotes(string, space, count_char);
		if (string[count_char] == space || string[count_char] == '\0')
			next = count_char;
		size = next - prev;
		if (size > 1 || (size == 1 && string[count_char - 1] != space))
			count_d += ft_addpart(&result[count_d], &string[prev], size, space);
		if (string[count_char] == '\0')
			break ;
		prev = next;
		count_char++;
	}
	result[count_d] = NULL;
}

size_t	ft_addpart(char **result, char *prev, size_t size, char c)
{
	if (*prev == c)
	{
		prev++;
		size--;
	}
	*result = (char *)malloc((size + 1) * sizeof(char));
	ft_strlcpy(*result, prev, size + 1);
	return (1);
}
