/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:38:35 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/09 17:04:32 by lebourre         ###   ########.fr       */
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

int		check_str(char *av)
{
	int		i;
	int		index;

	i = -1;
	while (av[++i])
		if (!ft_isdigit(av[i]) && !ft_ispace(av[i]))
			return (0);
	i = 0;
	while (av[i])
	{
		index = -1;
		if (ft_atoi(&av[i]) > 2147483647 || ft_atoi(&av[i]) < -2147483648)
			return (0);
		while (++index < i)
		{
			if (ft_atoi(&av[index]) == ft_atoi(&av[i]))
				return (0);
			index += skip_space(&av[index]);
			index += skip_digit(&av[index]);
		}
		i += skip_space(&av[i]);
		i += skip_digit(&av[i]);
	}
	return (1);
}

int		check_args(char **av)
{
	int		i;
	int		j;
	int		index;
	long	value;
	char	*ptr;

	i = -1;
	while (av[++i])
	{
		index = -1;
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (0);
		value = ft_atoi(av[i]);
		if (value > 2147483647 || value < -2147483648)
			return (0);
		while (++index < i)
		{
			ptr = av[index];
			if (ft_atoi(ptr) == ft_atoi(av[i]))
				return (0);
		}
	}
	return (1);
}
