/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_ten.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:38:25 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/28 15:30:57 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_else_reverse(t_stack *stack, t_options *options)
{
	int index;

	if ((index = insertion_place_reverse
(stack->b, ft_atoi(stack->a[0])))
			>= stack_len(stack->b) / 2)
	{
		while (stack->b[index + 1])
		{
			reverse_rotate(stack->b, 1, stack, options);
			index++;
		}
		push(stack->b, stack->a, 1, options);
	}
	else if ((index = insertion_place_reverse(stack->b, ft_atoi(stack->a[0])))
			< stack_len(stack->b) / 2)
	{
		while (index >= 0)
		{
			rotate(stack->b, 1, stack, options);
			index--;
		}
		push(stack->b, stack->a, 1, options);
	}
}

void	push_a_to_b_reverse_sort(t_stack *stk, int max, int min, t_options *opt)
{
	int i;
	int len;

	len = stack_len(stk->a);
	while (stack_len(stk->a) == len)
	{
		max = find_max(stk->b);
		min = find_min(stk->b);
		i = stack_len(stk->b) - 1;
		if (ft_atoi(stk->a[0]) > max && ft_atoi(stk->b[0]) == max)
			push(stk->b, stk->a, 1, opt);
		else if (ft_atoi(stk->a[0]) < min && min == ft_atoi(stk->b[i]))
		{
			push(stk->b, stk->a, 1, opt);
			rotate(stk->b, 1, stk, opt);
		}
		else
			next_else_reverse(stk, opt);
	}
}

void	set_closest_top_min_on_top(char **stack, int distance, t_stack *stk,
t_options *options)
{
	if (distance == 0)
		return ;
	else if (distance > 0)
		while (distance != 0)
		{
			rotate(stack, 0, stk, options);
			distance--;
		}
	else
		while (distance != 0)
		{
			reverse_rotate(stack, 0, stk, options);
			distance++;
		}
}
/*
void	set_value_to_top(char **stack, int index, int c, int odd)
{
	if (index <= (stack_len(stack) / 2) && odd == 0)
		while (index != 0)
		{
			rotate(stack, c, stack, options);
			index--;
		}
	else if (index > (stack_len(stack) / 2) && odd == 0)
		while (stack[index])
		{
			reverse_rotate(stack, c, stack, options);
			index++;
		}
	else if (index > (stack_len(stack) / 2) && odd == 1)
		while (stack[index])
		{
			reverse_rotate(stack, c, stack, options);
			index++;
		}
	else if (index <= (stack_len(stack) / 2) && odd == 1)
		while (index != 0)
		{
			rotate(stack, c, stack, options);
			index--;
		}
}*/

int		solve_ten(t_stack *stack, t_options *options)
{
	int		*five_min_tab;
	int		index;

	if (is_sorted(stack->a))
		return (1);
	index = 5;
	five_min_tab = 0;
	five_min_tab = get_chunck(five_min_tab, &index, stack->a, -1);
	push_closest_min(stack, 3, five_min_tab, options);
	solve_three_reverse(stack->b, 1, stack, options);
	push_min(stack, 2, options);
	fix_stack(stack->b, stack, options);
	if (stack_len(stack->a) > 3)
		solve_four_five(stack, stack_len(stack->a), options);
	else if (stack_len(stack->a) == 3)
		solve_three(stack->a, 0, stack, options);
	else if (stack_len(stack->a) == 2)
		if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[1]))
			swap(stack->a, 0, stack, options);
	while (stack->b[0])
		push(stack->a, stack->b, 0, options);
	free(five_min_tab);
	print_stack(stack->a, stack->b);
	return (1);
}
