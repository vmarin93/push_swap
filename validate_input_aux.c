/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:06:55 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/15 12:07:36 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_input_len(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) || str[i + 1] == '\0')
			len++;
		i++;
	}
	return (len);
}

void	free_input_matrix(char **input_matrix)
{
	int	i;

	i = 0;
	while (input_matrix[i] != NULL)
	{
		free(input_matrix[i]);
		i++;
	}
	free(input_matrix);
}

void	parse(int start, int end, char *input_string, char **input_matrix)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (input_string[i] != '\0')
	{
		if (input_string[i] == ' ' || input_string[i + 1] == '\0')
		{
			if (input_string[i] == ' ')
				end = i;
			else if (input_string[i + 1] == '\0')
				end = i + 1;
			input_matrix[k] = ft_split(start, end, input_string);
			if (input_matrix[k] == NULL)
				free_input_matrix(input_matrix);
			start = i + 1;
			k++;
		}
		i++;
	}
	input_matrix[k] = NULL;
}

char	**fill_input_matrix(char *input_string, int len)
{
	int		start;
	int		end;
	char	**input_matrix;

	input_matrix = malloc(sizeof(char *) * (len + 1));
	if (input_matrix == NULL)
		return (NULL);
	start = 0;
	end = 0;
	parse(start, end, input_string, input_matrix);
	return (input_matrix);
}

int	has_digits(char *argv1)
{
	int	i;

	i = 0;
	while (argv1[i] != '\0')
	{
		if (argv1[i] >= '0' && argv1[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}
