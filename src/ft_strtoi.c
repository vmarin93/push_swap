#include <limits.h>
#include <stddef.h>

int ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return 1;
	return 0;
}

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int ft_strtoi(const char *str, char **endptr)
{
	long result = 0;
	int sign = 1;
	int i = 0;
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
			*endptr = (char *)&str[i];
		return result;
	}
	while (ft_isdigit(str[i]))
	{
		int digit = str[i] - '0';
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
		{
			if (endptr != NULL)
				*endptr = (char *)&str[i];
			if (sign == 1)
				result = LONG_MAX;
			else
				result = LONG_MIN;
			return result;
		}
		result = result * 10 + digit;
		i++;
	}
	if (endptr != NULL)
		*endptr = (char *)&str[i];
	return (int)(result * sign);
}
