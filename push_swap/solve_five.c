#include "push_swap.h"

void	push_stack_b_back_to_stack_a(t_stack *t_stack, int max, int min)
{
	int i;

	i = 0;
	while (t_stack->b[0])
	{
		max = find_max(t_stack->a);
		min = find_min(t_stack->a);
		while (t_stack->a[i + 1])
			i++;
		if (ft_atoi(t_stack->b[0]) > max && ft_atoi(t_stack->a[i]) == max)
		{
			push(t_stack->a, t_stack->b, 0);
			rotate(t_stack->a, 0);
		}
		else if (ft_atoi(t_stack->b[0]) < min
		&& min == ft_atoi(t_stack->a[0]))
			push(t_stack->a, t_stack->b, 0);
		else if (ft_atoi(t_stack->b[0]) > ft_atoi(t_stack->a[0]))
			rotate(t_stack->a, 0);
		else
			push(t_stack->a, t_stack->b, 0);
	}
}

int		solve_four_five(t_stack *t_stack)
{
	int i;
	int stack_size;

	stack_size = stack_len(t_stack->a);
	i = stack_size;
	while (i != 3)
	{
		push(t_stack->b, t_stack->a, 1);
		i--;
	}
	if (ft_atoi(t_stack->b[0]) > ft_atoi(t_stack->b[1]))
		swap(t_stack->b, 1);
	solve_three(t_stack->a, 0);
	push_stack_b_back_to_stack_a(t_stack, 0, 0);
	if (is_sorted(t_stack->a))
		return (1);
	i = -1;
	while(t_stack->a[++i])
	{
		if (ft_atoi(t_stack->a[i]) > ft_atoi(t_stack->a[i + 1]))
		{
			i++;
			break ;
		}
	}
	if (i > (stack_size / 2))
		while (!is_sorted(t_stack->a))
			reverse_rotate(t_stack->a, 0);
	else
		while (!is_sorted(t_stack->a))
			rotate(t_stack->a, 0);
	return (1);
}
