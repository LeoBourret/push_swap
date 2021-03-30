/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:52:52 by lebourre          #+#    #+#             */
/*   Updated: 2021/03/30 11:26:52 by lebourre         ###   ########.fr       */
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
			if (ft_atoi(ptr) == ft_atoi(av[i]))
				return (0);
		}
	}
	return (1);
}

int		set_stack(int ac, char **av, t_stack *t_stack)
{
	int i;

	i = -1;
	t_stack->a = malloc(sizeof(char *) * (ac + 1));
	t_stack->b = malloc(sizeof(char *) * (ac + 1));
	if (t_stack->a == NULL || t_stack->b == NULL)
		return (0);
	while (av[++i])
		t_stack->a[i] = ft_strdup(av[i]);
	t_stack->a[i] = NULL;
	i = -1;
	while (++i <= ac)
		t_stack->b[i] = NULL;
	return (1);
}

char	**get_orders(char **orders)
{
	int i;
	int ret;

	i = -1;
	orders = NULL;
	orders = ft_realloc_double(orders);
	while ((ret = get_next_line(0, &orders[++i])) > 0)
		orders = ft_realloc_double(orders);
	if (ret < 0)
	{
		i = -1;
		while (orders[++i])
			free(orders[i]);
		free(orders);
		return (NULL);
	}
	orders[i] = NULL;
	return (orders);
}

void	checker(int ac, char **av, t_stack *t_stack)
{
	char		**orders;
	int			i;

	if (!check_args(av))
	{
		ft_printf("Error\n");
		return ;
	}
	set_stack(ac, av, t_stack);
	print_stack(t_stack->a, NULL);
	orders = get_orders(orders);
	if (!(execute_orders(t_stack, orders)))
		return ;
	i = -1;
	i = 0;
	while (t_stack->a[i + 1])
	{
		if (ft_atoi(t_stack->a[i]) > ft_atoi(t_stack->a[i + 1]))
		{
			ft_printf("KO\n");
			return ;
		}
		i++;
	}
	ft_printf("OK\n");
}

int		main(int ac, char **av)
{
	t_stack *t_stack;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	t_stack = malloc(sizeof(t_stack));
	if (t_stack == NULL)
		return (0);
	checker(ac - 1, av + 1, t_stack);
	return (0);
}
