/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_ten.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:38:25 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/09 17:08:01 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_else_reverse(t_stack *stack)
{
	int index;

	if ((index = insertion_place_reverse
(stack->b, ft_atoi(stack->a[0])))
			>= stack_len(stack->b) / 2)
	{
		while (stack->b[index + 1])
		{
			reverse_rotate(stack->b, 1);
			index++;
		}
		push(stack->b, stack->a, 1);
	}
	else if ((index = insertion_place_reverse(stack->b, ft_atoi(stack->a[0])))
			< stack_len(stack->b) / 2)
	{
		while (index >= 0)
		{
			rotate(stack->b, 1);
			index--;
		}
		push(stack->b, stack->a, 1);
	}
}

void	push_a_elem_to_b_reverse_sort(t_stack *stack, int max, int min)
{
	int i;
	int len;
	int index;

	len = stack_len(stack->a);
	while (stack_len(stack->a) == len)
	{
		max = find_max(stack->b);
		min = find_min(stack->b);
		i = stack_len(stack->b) - 1;
		if (ft_atoi(stack->a[0]) > max && ft_atoi(stack->b[0]) == max)
			push(stack->b, stack->a, 1);
		else if (ft_atoi(stack->a[0]) < min && min == ft_atoi(stack->b[i]))
		{
			push(stack->b, stack->a, 1);
			rotate(stack->b, 1);
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

int		solve_ten(t_stack *stack)
{
	int		five_min_tab[5];
	int		i;
	int		min;
	int		j;
	int		index;

	i = -1;
	min = find_min(stack->a);
	index = find_max(stack->a);
	while (++i < 4)
		five_min_tab[i] = min;
	i = 0;
	while (++i < 5)
	{
		j = -1;
		min = index;
		while (stack->a[++j])
		{
			if (min > ft_atoi(stack->a[j])
			&& !is_in_tab(five_min_tab, ft_atoi(stack->a[j]), 5))
				min = ft_atoi(stack->a[j]);
		}
		five_min_tab[i] = min;
	}
	index = -1;
	while (++index < 3)
	{
		i = 0;
		j = stack_len(stack->a) - 1;
		while (!is_in_tab(five_min_tab, ft_atoi(stack->a[i]), 5))
			i++;
		while (!is_in_tab(five_min_tab, ft_atoi(stack->a[j]), 5))
			j--;
		j = (j - stack_len(stack->a)) * -1;
		set_closest_top_min_on_top(stack->a, i, j);
		push(stack->b, stack->a, 1);
	}
	solve_three_reverse(stack->b, 1);
	while (stack_len(stack->a) != 5)
	{
		min = find_min(stack->a);
		i = 0;
		while (ft_atoi(stack->a[i]) != min)
			i++;
		set_value_to_top(stack->a, i, 0, stack_len(stack->a) % 2);
		push_a_elem_to_b_reverse_sort(stack, 0, 0);

	}
	if (!is_sorted_reverse(stack->b))
	{
		i = -1;
		while (stack->b[++i])
			if (ft_atoi(stack->b[i]) < ft_atoi(stack->b[i + 1]))
			{
				i++;
				break ;
			}
		if (i > (stack_len(stack->b) / 2))
		{
			while (!is_sorted_reverse(stack->b))
				reverse_rotate(stack->b, 1);
		}
		else
			while (!is_sorted_reverse(stack->b))
				rotate(stack->b, 1);
	}
	if (stack_len(stack->a) > 3)
	solve_four_five(stack);
	while (stack->b[0])
		push(stack->a, stack->b, 0);
	return (1);
}
