/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:13 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/09 16:26:16 by lebourre         ###   ########.fr       */
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

void	push_a_correct_order(t_stack *t_stack, int max, int min, int size)
{
	int i;
	int index;

	i = 0;
	while (stack_len(t_stack->a) != size)
	{
		max = find_max(t_stack->a);
		min = find_min(t_stack->a);
		i = stack_len(t_stack->a) - 1;
		if (ft_atoi(t_stack->b[0]) > max && ft_atoi(t_stack->a[i]) == max)
		{
			push(t_stack->a, t_stack->b, 0);
			rotate(t_stack->a, 0);
		}
		else if (ft_atoi(t_stack->b[0]) < min && min == ft_atoi(t_stack->a[0]))
			push(t_stack->a, t_stack->b, 0);
		else if ((index = insertion_place(t_stack->a, ft_atoi(t_stack->b[0])))
		>= stack_len(t_stack->a) / 2)
		{
			while (t_stack->a[index + 1])
			{
				reverse_rotate(t_stack->a, 0);
				index++;
			}
			push(t_stack->a, t_stack->b, 0);
		}
		else if ((index = insertion_place(t_stack->a, ft_atoi(t_stack->b[0])))
		< stack_len(t_stack->a) / 2)
		{
			while (index >= 0)
			{
				rotate(t_stack->a, 0);
				index--;
			}
			push(t_stack->a, t_stack->b, 0);
		}
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
	push_a_correct_order(t_stack, 0, 0, stack_size);
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
	{
		while (!is_sorted(t_stack->a))
			rotate(t_stack->a, 0);
	}
	return (1);
}
