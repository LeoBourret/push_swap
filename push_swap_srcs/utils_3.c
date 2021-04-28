/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:38:35 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/28 15:24:37 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (value < ft_atoi(stack[i])
		&& ft_atoi(stack[i]) < ft_atoi(stack[i + 1]))
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

void	push_closest_min(t_stack *stack, int to_find, int *chunck,
t_options *opt)
{
	int index;
	int i;
	int j;

	index = -1;
	while (++index < to_find)
	{
		i = 0;
		j = stack_len(stack->a) - 1;
		while (!is_in_tab(chunck, ft_atoi(stack->a[i]), 5))
			i++;
		while (!is_in_tab(chunck, ft_atoi(stack->a[j]), 5))
			j--;
		j = (j - stack_len(stack->a)) * -1;
		if (i <= j)
			set_closest_top_min_on_top(stack->a, i, stack, opt);
		push(stack->b, stack->a, 1, opt);
	}
}

int		check_str(char *av)
{
	int		i;
	int		index;

	i = -1;
	while (av[++i])
		if ((!ft_isdigit(av[i]) && !ft_ispace(av[i]) && av[i] != '-')
		|| (i != 0 && av[i] == '-' && av[i - 1] != ' '))
			return (0);
	i = 0;
	while (av[i])
	{
		index = -1;
		if (ft_atoi(&av[i]) > 2147483647 || ft_atoi(&av[i]) < -2147483648)
			return (0);
		while (++index < i && av[i + 1])
		{
			if (ft_atoi(&av[index]) == ft_atoi(&av[i]))
				return (0);
			index += skip_space(&av[index]);
			if (av[index] == '-')
				index++;
			index += skip_digit(&av[index]);
		}
		i += skip_space(&av[i]);
		if (av[i] == '-')
				i++;
		i += skip_digit(&av[i]);
	}
	return (1);
}
/*
int		check_args(char *stack)
{
	int		i;
	int		j;
	int		index;
	long	value;
	char	*ptr;

	i = 0;
	while (stack[i])
	{
		index = -1;
		if (!ft_isdigit(stack[i][j]) && stack[i][j] != '-'
		&& (j != 0 && stack[i][j] == '-' && stack[i][j - 1] != ' '))
			return (0);
		value = ft_atoi(&stack[i]);
		if (value > 2147483647 || value < -2147483648)
			return (0);
		while (++index < i)
		{
			ptr = stack[index];
			if (ft_atoi(ptr) == ft_atoi(stack[i]))
				return (0);
		}
	}
	return (1);
}*/
