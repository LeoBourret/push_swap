/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:33:24 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/12 13:33:30 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(char **stack)
{
	int i;

	i = 0;
	while (stack[i + 1])
	{
		if (ft_atoi(stack[i]) > ft_atoi(stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int		is_sorted_reverse(char **stack)
{
	int i;

	i = 0;
	while (stack[i + 1])
	{
		if (ft_atoi(stack[i]) < ft_atoi(stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int		find_min(char **stack)
{
	int i;
	int min_value;

	i = -1;
	min_value = ft_atoi(stack[0]);
	while (stack[++i])
	{
		if (ft_atoi(stack[i]) < min_value)
			min_value = ft_atoi(stack[i]);
	}
	return (min_value);
}
