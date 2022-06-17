/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:29:11 by felcaue-          #+#    #+#             */
/*   Updated: 2022/06/09 18:46:58 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_odd_quotes(char *text);

void	sort_command(char *input)
{
	t_list		*command_w_tokens;
	char		**command_line;
	int			counter;

	if (!ft_odd_quotes(input))
	{
		command_line = ft_split_command(input, ' ');
		counter = 0;
		while (command_line[counter])
		{
			printf("%s\n", command_line[counter]);
			counter++;
		}
		g_data.c_list = start_token(command_line);
		command_w_tokens = start_token(command_line);
		while (command_w_tokens != NULL)
		{
			printf("%s e token %i, ", command_w_tokens->input, command_w_tokens->token);
			command_w_tokens = command_w_tokens->next;
		}
		command_w_tokens = find_first_token(command_w_tokens);
		printf("\n");
	}
}

int	ft_odd_quotes(char *text)
{
	int	counter;
	int	count_double_quotes;
	int	count_single_quotes;

	counter = 0;
	count_double_quotes = 0;
	count_single_quotes = 0;
	while (text[counter] != '\0')
	{
		if (text[counter] == 34)
			count_double_quotes++;
		else if (text[counter] == 39)
			count_single_quotes++;
		counter++;
	}
	if (count_double_quotes % 2 != 0 || count_single_quotes % 2 != 0)
	{
		printf("Error: command has an odd number of quotes\n");
		return (1);
	}
	else
		return (0);
}
