/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:34:55 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/09 09:39:06 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	handle_overflow(unsigned long result, int digit, int sign)
{
	unsigned long	cutoff;
	int				cutlimit;

	if (sign == -1)
		cutoff = -(long)INT_MIN;
	else
		cutoff = INT_MAX;
	cutlimit = cutoff % 10;
	cutoff /= 10;
	if (result > cutoff || (result == cutoff && digit > cutlimit))
	{
		if (sign == -1)
			return (LONG_MIN);
		else
			return (LONG_MAX);
	}
	return (result);
}

long	do_conversion(char *str, char **endptr, int i, int sign)
{
	int				digit;
	long			overflow;
	unsigned long	result;

	result = 0;
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		overflow = handle_overflow(result, digit, sign);
		if (overflow == LONG_MAX || overflow == LONG_MIN)
		{
			if (endptr != NULL)
				*endptr = &str[i];
			return (overflow);
		}
		result = result * 10 + digit;
		i++;
	}
	if (endptr != NULL)
		*endptr = (char *)&str[i];
	return (result);
}

long	ft_strtol(char *str, char **endptr)
{
	long	result;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
	{
		if (endptr != NULL)
			*endptr = &str[i];
		return (LONG_MAX);
	}
	result = do_conversion(str, endptr, i, sign);
	return (result * sign);
}
