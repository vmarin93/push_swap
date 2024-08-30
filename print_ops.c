#include "push_swap.h"

int print_ops(char **ops)
{
	int	i;
	int	op_count;

	printf("\n");
	printf("Operations: \n");
	i = 0;
	op_count = 0;
	while(ops[i + 1] != NULL)
	{
		if ((ft_strcmp(ops[i], "sa\n") && ft_strcmp(ops[i + 1], "sb\n"))
				|| (ft_strcmp(ops[i], "sb\n") && ft_strcmp(ops[i + 1], "sa\n")))
		{
			printf("ss\n");
			op_count++;
			i += 2;
		}
		else if ((ft_strcmp(ops[i], "ra\n") && ft_strcmp(ops[i + 1], "rb\n"))
				|| (ft_strcmp(ops[i], "rb\n") && ft_strcmp(ops[i + 1], "ra\n")))
		{
			printf("rr\n");
			op_count++;
			i += 2;
		}
		else if ((ft_strcmp(ops[i], "rra\n") && ft_strcmp(ops[i + 1], "rrb\n"))
				|| (ft_strcmp(ops[i], "rrb\n") && ft_strcmp(ops[i + 1], "rra\n")))
		{
			printf("rrr\n");
			op_count++;
			i += 2;
		}
		else
		{
			printf("%s", ops[i]);
			i++;
			op_count++;
		}
	}
	return (op_count);
}
