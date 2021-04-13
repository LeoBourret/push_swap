/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_ten.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:38:25 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/13 14:51:17 by lebourre         ###   ########.fr       */
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
		else
			next_else_reverse(stack);
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
	int		*five_min_tab;
	int		i;
	int		index;

	if (is_sorted(stack->a))
		return (1);
	index = 5;
	five_min_tab = 0;
	five_min_tab = get_chunck(five_min_tab, &index, stack->a, -1);
	i = 0;
	index = -1;
	push_closest_min(stack, 3, five_min_tab);
	solve_three_reverse(stack->b, 1);
	push_min(stack, 2);
	fix_stack(stack->b);
	if (stack_len(stack->a) > 3)
		solve_four_five(stack, stack_len(stack->a));
	while (stack->b[0])
		push(stack->a, stack->b, 0);
	free(five_min_tab);
	print_stack(stack->a, stack->b);
	return (1);
}
