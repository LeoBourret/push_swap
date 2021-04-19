/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:52:52 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/19 15:02:49 by lebourre         ###   ########.fr       */
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

int		set_stack(int ac, char **av, t_stack *stack)
{
	int i;

	i = -1;
	stack->a = malloc(sizeof(char *) * (ac + 1));
	stack->b = malloc(sizeof(char *) * (ac + 1));
	if (stack->a == NULL || stack->b == NULL)
		return (0);
	while (av[++i])
		stack->a[i] = ft_strdup(av[i]);
	stack->a[i] = NULL;
	i = -1;
	while (++i <= ac)
		stack->b[i] = NULL;
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

void	checker(int ac, char **av, t_stack *stack)
{
	char	**orders;
	int		i;

	if (!check_args(av))
	{
		ft_printf("Error\n");
		return ;
	}
	set_stack(ac, av, stack);
	print_stack(stack->a, NULL);
	orders = get_orders(orders);
	if (!(execute_orders(stack, orders)))
		return ;
	i = -1;
	i = 0;
	while (stack->a[i + 1])
	{
		if (ft_atoi(stack->a[i]) > ft_atoi(stack->a[i + 1]))
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
	t_stack *stack;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (0);
	checker(ac - 1, av + 1, stack);
	while (1)
		;
	return (0);
}
