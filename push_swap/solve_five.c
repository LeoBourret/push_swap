/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:13 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/13 14:47:03 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		insertion_place(char **stack, int value)
{
	int i;

	i = 0;
	while (stack[i + 1])
	{
		if (value > ft_atoi(stack[i]) && value < ft_atoi(stack[i + 1]))
			break ;
		else if (value > ft_atoi(stack[i]) && value > ft_atoi(stack[i + 1])
		&& ft_atoi(stack[i]) > ft_atoi(stack[i + 1]))
			break ;
		i++;
	}
	return (i);
}

void	next_else(t_stack *stack)
{
	int index;

	index = 0;
	if ((index = insertion_place(stack->a, ft_atoi(stack->b[0])))
	>= stack_len(stack->a) / 2)
	{
		while (stack->a[index + 1] && index++)
			reverse_rotate(stack->a, 0);
		push(stack->a, stack->b, 0);
	}
	else if ((index = insertion_place(stack->a, ft_atoi(stack->b[0])))
	< stack_len(stack->a) / 2)
	{
		while (index >= 0)
		{
			rotate(stack->a, 0);
			index--;
		}
		push(stack->a, stack->b, 0);
	}
}

void	push_a_correct_order(t_stack *stack, int max, int min, int size)
{
	int i;

	i = 0;
	while (stack_len(stack->a) != size)
	{
		max = find_max(stack->a);
		min = find_min(stack->a);
		i = stack_len(stack->a) - 1;
		if (ft_atoi(stack->b[0]) > max && ft_atoi(stack->a[i]) == max)
		{
			push(stack->a, stack->b, 0);
			rotate(stack->a, 0);
		}
		else if (ft_atoi(stack->b[0]) < min && min == ft_atoi(stack->a[0]))
			push(stack->a, stack->b, 0);
		else
			next_else(stack);
	}
}

int		solve_four_five(t_stack *stack, int stack_size)
{
	int i;

	if (is_sorted(stack->a))
		return (1);
	i = stack_size;
	while (i != 3 && i--)
		push(stack->b, stack->a, 1);
	if (ft_atoi(stack->b[0]) > ft_atoi(stack->b[1]))
		swap(stack->b, 1);
	solve_three(stack->a, 0);
	push_a_correct_order(stack, 0, 0, stack_size);
	if (is_sorted(stack->a))
		return (1);
	i = -1;
	while (stack->a[++i])
		if (ft_atoi(stack->a[i]) > ft_atoi(stack->a[i + 1]))
			break ;
	if (i > (stack_size / 2))
		while (!is_sorted(stack->a))
			reverse_rotate(stack->a, 0);
	else
		while (!is_sorted(stack->a))
			rotate(stack->a, 0);
	return (1);
}
