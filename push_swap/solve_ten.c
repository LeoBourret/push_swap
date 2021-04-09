#include "push_swap.h"

int		is_in_tab(int *tab, int value, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] == value)
			return (1);
	return (0);
}

int		insertion_place_reverse(char **stack, int value)
{
	int i;

	i = 0;
	while (stack[i + 1])
	{
		if (value < ft_atoi(stack[i]) && ft_atoi(stack[i]) < ft_atoi(stack[i + 1]))
			break ;
		else if (value < ft_atoi(stack[i]) && value > ft_atoi(stack[i + 1]))
			break ;
		else if (value > ft_atoi(stack[i]) && value > ft_atoi(stack[i + 1])
		&& ft_atoi(stack[i]) < ft_atoi(stack[i + 1]))
			break ;
		i++;
	}
	return (i);
}

void	push_a_elem_to_b_reverse_sort(t_stack *t_stack, int max, int min)
{
	int i;
	int len;
	int index;

	len = stack_len(t_stack->a);
	while (stack_len(t_stack->a) == len)
	{
		max = find_max(t_stack->b);
		min = find_min(t_stack->b);
		i = stack_len(t_stack->b) - 1;
		if (ft_atoi(t_stack->a[0]) > max && ft_atoi(t_stack->b[0]) == max)
			push(t_stack->b, t_stack->a, 1);
		else if (ft_atoi(t_stack->a[0]) < min && min == ft_atoi(t_stack->b[i]))
		{
			push(t_stack->b, t_stack->a, 1);
			rotate(t_stack->b, 1);
		}
		else if ((index = insertion_place_reverse(t_stack->b, ft_atoi(t_stack->a[0])))
		>= stack_len(t_stack->b) / 2)
		{
			while (t_stack->b[index + 1])
			{
				reverse_rotate(t_stack->b, 1);
				index++;
			}
			push(t_stack->b, t_stack->a, 1);
		}
		else if ((index = insertion_place_reverse(t_stack->b, ft_atoi(t_stack->a[0])))
		< stack_len(t_stack->b) / 2)
		{
			while (index >= 0)
			{
				rotate(t_stack->b, 1);
				index--;
			}
			push(t_stack->b, t_stack->a, 1);
		}
	}
}

void	set_closest_top_min_on_top(char **stack, int front, int back)
{
		if (front == 0)
			return ;
		else if (front <= back || front - back == 1)
			while (front != 0)
			{
				rotate(stack, 0);
				front--;
			}
		else
			while (back != 0)
			{
				reverse_rotate(stack, 0);
				back--;
			}
}

void	set_value_to_top(char **stack, int index, int c, int odd)
{
	if (index <= (stack_len(stack) / 2) && odd == 0)
		while (index != 0)
		{
			rotate(stack, c);
			index--;
		}
	else if (index > (stack_len(stack) / 2) && odd == 0)
		while (stack[index])
		{
			reverse_rotate(stack, c);
			index++;
		}
	else if (index > (stack_len(stack) / 2) && odd == 1)
		while (stack[index])
		{
			reverse_rotate(stack, c);
			index++;
		}
	else if (index <= (stack_len(stack) / 2) && odd == 1)
		while (index != 0)
		{
			rotate(stack, c);
			index--;
		}
}

int		solve_ten(t_stack *t_stack)
{
	int		five_min_tab[5];
	int		i;
	int		min;
	int		j;
	int		index;

	i = -1;
	min = find_min(t_stack->a);
	index = find_max(t_stack->a);
	while (++i < 4)
		five_min_tab[i] = min;
	i = 0;
	while (++i < 5)
	{
		j = -1;
		min = index;
		while (t_stack->a[++j])
		{
			if (min > ft_atoi(t_stack->a[j])
			&& !is_in_tab(five_min_tab, ft_atoi(t_stack->a[j]), 5))
				min = ft_atoi(t_stack->a[j]);
		}
		five_min_tab[i] = min;
	}
	index = -1;
	while (++index < 3)
	{
		i = 0;
		j = stack_len(t_stack->a) - 1;
		while (!is_in_tab(five_min_tab, ft_atoi(t_stack->a[i]), 5))
			i++;
		while (!is_in_tab(five_min_tab, ft_atoi(t_stack->a[j]), 5))
			j--;
		j = (j - stack_len(t_stack->a)) * -1;
		set_closest_top_min_on_top(t_stack->a, i, j);
		push(t_stack->b, t_stack->a, 1);
	}
	solve_three_reverse(t_stack->b, 1);
	while (stack_len(t_stack->a) != 5)
	{
		min = find_min(t_stack->a);
		i = 0;
		while (ft_atoi(t_stack->a[i]) != min)
			i++;
		set_value_to_top(t_stack->a, i, 0, stack_len(t_stack->a) % 2);
		push_a_elem_to_b_reverse_sort(t_stack, 0, 0);

	}
	if (!is_sorted_reverse(t_stack->b))
	{
		i = -1;
		while (t_stack->b[++i])
			if (ft_atoi(t_stack->b[i]) < ft_atoi(t_stack->b[i + 1]))
			{
				i++;
				break ;
			}
		if (i > (stack_len(t_stack->b) / 2))
		{
			while (!is_sorted_reverse(t_stack->b))
				reverse_rotate(t_stack->b, 1);
		}
		else
			while (!is_sorted_reverse(t_stack->b))
				rotate(t_stack->b, 1);
	}
	if (stack_len(t_stack->a) > 3)
	solve_four_five(t_stack);
	while (t_stack->b[0])
		push(t_stack->a, t_stack->b, 0);
	return (1);
}
