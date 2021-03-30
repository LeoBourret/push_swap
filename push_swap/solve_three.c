#include "push_swap.h"

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
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
		return (1);
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		rotate(stack);
		ft_printf("ra\n");
		return (1);
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		swap(stack);
		reverse_rotate(stack);
		ft_printf("sa\nrra\n");
		return (1);
	}
	return (1);
}

int		find_max(char **stack)
{
	int i;
	int max_value;

	i = -1;
	max_value = 0;
	while (stack[++i])
	{
		if (ft_atoi(stack[i]) > max_value)
			max_value = ft_atoi(stack[i]);
	}
	return (max_value);
}

int		solve_four_five(t_stack *t_stack)
{
	int i;
	int stack_size;
	int max_value;

	stack_size = 0;
	while (t_stack->a[stack_size])
		stack_size++;
	i = stack_size;
	while (i != 3)
	{
		push(t_stack->b, t_stack->a);
		ft_printf("pb\n");
		i--;
	}
	if (ft_atoi(t_stack->b[0]) < ft_atoi(t_stack->b[1]))
	{
		swap(t_stack->b);
		ft_printf("sa\n");
	}
	solve_three(t_stack->a);
	print_stack(t_stack->a, t_stack->b);
	while (t_stack->b[0])
	{
		max_value = find_max(t_stack->a);
		if (ft_atoi(t_stack->b[0]) > max_value)
		{
			push(t_stack->a, t_stack->b);
			rotate(t_stack->a);
			ft_printf("pa\nra\n");
//			print_stack(t_stack->a, t_stack->b);
		}
		else if (ft_atoi(t_stack->b[0]) > ft_atoi(t_stack->a[0]))
		{
			rotate(t_stack->a);
			ft_printf("ra\n");
//			print_stack(t_stack->a, t_stack->b);
		}
		else
		{
			push(t_stack->a, t_stack->b);
			ft_printf("pa\n");
//			print_stack(t_stack->a, t_stack->b);
		}
	}
	if (is_sorted(t_stack->a))
		return (1);
	i = -1;
	while(ft_atoi(t_stack->a[++i]))
	{
		if (ft_atoi(t_stack->a[i]) > ft_atoi(t_stack->a[i + 1]))
		{
			i++;
			break ;
		}
	}
	print_stack(t_stack->a, t_stack->b);
	if (i >= (stack_size / 2))
		while (!is_sorted(t_stack->a))
		{
			reverse_rotate(t_stack->a);
//			ft_printf("rra\n");
//			print_stack(t_stack->a, t_stack->b);
		}
	else
		while (!is_sorted(t_stack->a))
		{
			rotate(t_stack->a);
//			ft_printf("ra\n");
//			print_stack(t_stack->a, t_stack->b);
		}
	return (1);
}
