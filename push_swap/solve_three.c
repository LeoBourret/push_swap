#include "push_swap.h"

void		solve_three_reverse_2(char **stack, int c)
{
	if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		reverse_rotate(stack, c);
		return ;
	}
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		swap(stack, c);
		return ;
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		reverse_rotate(stack, c);
		swap(stack, c);
		return ;
	}
}

void	solve_three_reverse(char **stack, int c)
{
	if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2]))
	{
		return ;
	}
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		rotate(stack, c);
		swap(stack, c);
		return ;
	}
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		rotate(stack, c);
		return ;
	}
	solve_three_reverse_2(stack, c);
}

void	solve_three_2(char **stack, int c)
{
	if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		reverse_rotate(stack, c);
		return ;
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		rotate(stack, c);
		return ;
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		swap(stack, c);
		reverse_rotate(stack, c);
		return ;
	}
}

int		solve_three(char **stack, int c)
{
	if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2]))
		return (1);
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		swap(stack, c);
		rotate(stack, c);
		return (1);
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		swap(stack, c);
		return (1);
	}
	else
		solve_three_2(stack, c);
	return (1);
}
