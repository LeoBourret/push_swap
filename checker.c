/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:52:52 by lebourre          #+#    #+#             */
/*   Updated: 2021/03/11 16:46:51 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			if ((ft_strncmp(ptr, av[i], ft_strlen(ptr))) == 0)
				return (0);
		}
	}
	return (1);
}

int		set_stack(int ac, char **av, t_stack *t_stack)
{
	int i;

	i = -1;
	t_stack->a = malloc(sizeof(int) * ac);
	t_stack->b = malloc(sizeof(int) * ac);
	if (t_stack->a == NULL || t_stack->b == NULL)
		return (0);
	while (av[++i])
		t_stack->a[i] = ft_atoi(av[i]);
	return (1);
}

int		get_orders(char **orders)
{
	int i;
	int ret;

	i = 1;
	orders = ft_realloc_double(orders);
	while ((ret = get_next_line(0, &orders[++i])) > 0)
		orders = ft_realloc_double(orders);
	return (1);
}

void	checker(int ac, char **av)
{
	t_stack		*t_stack;
	char		**orders;

	if (!check_args(av))
	{
		ft_printf("Error\n");
		return ;
	}
	set_stack(ac, av, t_stack);
	get_orders(orders);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_printf("Error\n");
	else if (ac > 2)
		checker(ac - 1, av + 1);
	return (0);
}
