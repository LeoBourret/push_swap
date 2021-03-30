#include "push_swap.h"

void	solve_three_2(char **stack)
{
	if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
		return ;
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		rotate(stack);
		ft_printf("ra\n");
		return ;
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		swap(stack);
		reverse_rotate(stack);
		ft_printf("sa\nrra\n");
		return ;
	}
}

int		solve_three(char **stack)
{
	if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2]))
		return (1);
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		swap(stack);
		rotate(stack);
		ft_printf("sa\nra\n");
		return (1);
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		swap(stack);
		ft_printf("sa\n");
		return (1);
	}
	else
		solve_three_2(stack);
	return (1);
}
