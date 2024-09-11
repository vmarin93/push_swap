/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:23:29 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/11 10:24:42 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	is_sorted(t_Stack *stack)
{
	int	value;
	int	i;

	if (!stack)
		return (0);
	value = stack->numbers[stack->top];
	i = stack->size - 1;
	while (i > 0)
	{
		if (stack->numbers[i - 1] < value)
			return (0);
		value = stack->numbers[i - 1];
		i--;
	}
	return (1);
}

long	stack_sum(t_Stack *stack)
{
	long	sum;
	int		i;

	if (!stack)
		return (0);
	sum = 0;
	i = stack->top;
	while (i >= 0)
	{
		sum += stack->numbers[i];
		i--;
	}
	return (sum);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	if (str == NULL)
		return (NULL);
	dup = malloc(ft_strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
