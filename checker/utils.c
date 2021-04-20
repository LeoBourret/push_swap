/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:14:12 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/20 17:17:02 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		stack_len(char **stack)
{
	int i;

	i = 0;
	while (stack[i] != NULL)
		i++;
	return (i);
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

int		set_stack(char **av, t_stack *stack)
{
	int		i;
	int		index;
	char	*args;

	i = -1;
	index = 0;
	args = join_args(av);
	stack->a = ft_split(args, ' ');
	free(args);
	if (!check_args(stack->a))
	{
		ft_printf("Error\n");
		return (0);
	}
	stack->b = malloc(sizeof(char *) * (stack_len(stack->a) + 1));
	if (stack->b == NULL)
		return (0);
	i = -1;
	while (++i <= stack_len(stack->a))
		stack->b[i] = NULL;
	return (1);
}

int		manage_orders(char **orders, t_stack *stack, int verbose)
{
	int i;
	int ret;

	i = -1;
	orders = NULL;
	orders = ft_realloc_double(orders);
	while ((ret = get_next_line(0, &orders[++i])) > 0)
	{
		if (!(execute_orders(stack, orders[i], verbose)))
		{
			free(orders);
			return (-1);
		}
		orders = ft_realloc_double(orders);
		
	}
	if (ret < 0)
	{
		ft_printf("Error malloc\n");
		return (-2);
	}
	free_orders(orders);
	return (1);
}
