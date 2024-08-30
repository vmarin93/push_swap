#include "push_swap.h"

int *do_int_conversion(int argc, char *argv[])
{
	int	*input;
	int	i;
	long	number;
	char	*endptr;

	input = malloc(sizeof(int) * (argc - 1));
	if (input == NULL)
		exit(1);
	i = 0;
	while (i < argc - 1)
	{
		number = ft_strtol(argv[i + 1], &endptr);
		if (*endptr != '\0' || endptr == argv[i + 1] || number == LONG_MAX || number == LONG_MIN)
		{
			write(2, "Error\n", 6);
			free(input);
			exit(1);
		}
		input[i] = (int)number;
		i++;
	}
	return (input);
}

int check_for_duplicates(int *input, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void fill_stack(int *input, int len, Stack *stack_a)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		push(stack_a, input[i]);
		i--;
	}
}

void validate_input(int argc, char *argv[], Stack *stack_a)
{
	int	*input;
	int	duplicates;

	if (argc < 2)
		exit(1);
	input = do_int_conversion(argc, argv);
	duplicates = check_for_duplicates(input, argc - 1);
	if (duplicates)
	{
		write(2, "Error\n", 6);
		free(input);
		exit (1);
	}
	fill_stack(input, argc - 1, stack_a);
	free(input);
}
