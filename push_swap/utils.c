#include "push_swap.h"

int		is_sorted(char **stack)
{
	int i;

	i = 0;
	while (stack[i + 1])
	{
		if (ft_atoi(stack[i]) > ft_atoi(stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
