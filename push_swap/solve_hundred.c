/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:19:53 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/12 14:54:10 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*get_chunck(int *tab, int *size, char **stack, int i)
{
	int min;
	int max;
	int j;

	min = find_min(stack);
	max = find_max(stack);
	if (*size > stack_len(stack))
		*size = stack_len(stack);
	tab = malloc(sizeof(int) * *size);
	if (!tab)
		return (0);
	while (++i < *size)
		tab[i] = min;
	i = 0;
	while (++i < *size)
	{
		min = max;
		j = -1;
		while (stack[++j])
			if (min > ft_atoi(stack[j])
			&& !is_in_tab(tab, ft_atoi(stack[j]), *size))
				min = ft_atoi(stack[j]);
		tab[i] = min;
	}
	return (tab);
}

int		push_back(t_stack *stack)
{
	int i;

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
	while (stack_len(stack->b))
		push(stack->a, stack->b, 0);
	return (1);
}

void	solve_hundred(t_stack *stack, int size_chunck, int *chunck)
{
	int i;
	int j;
	int index;

	if (stack_len(stack->a) == 0 && push_back(stack))
		return ;
	chunck = get_chunck(chunck, &size_chunck, stack->a, -1);
	index = -1;
	while (++index < size_chunck)
	{
		i = 0;
		j = stack_len(stack->a) - 1;
		while (!is_in_tab(chunck, ft_atoi(stack->a[i]), size_chunck))
			i++;
		while (!is_in_tab(chunck, ft_atoi(stack->a[j]), size_chunck))
			j--;
		j = (j - stack_len(stack->a)) * -1;
		set_closest_top_min_on_top(stack->a, i, j);
		if (stack_len(stack->b) == 0 || stack_len(stack->b) == 1)
			push(stack->b, stack->a, 1);
		else
			push_a_elem_to_b_reverse_sort(stack, 0, 0);
	}
	free(chunck);
	solve_hundred(stack, size_chunck, 0);
}
