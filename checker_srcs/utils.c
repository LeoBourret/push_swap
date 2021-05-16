/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:14:12 by lebourre          #+#    #+#             */
/*   Updated: 2021/05/16 16:19:25 by lebourre         ###   ########.fr       */
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

int		ft_ispace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int		check_str(char *av, int i, int index)
{
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

int		set_stack(char **av, t_stack *stack)
{
	int		i;
	int		index;
	char	*args;

	i = -1;
	index = 0;
	args = join_args(av);
	if (!check_str(args, -1, -1))
	{
		ft_printf("Error\n");
		free(args);
		return (0);
	}
	stack->a = ft_split(args, ' ');
	free(args);
	stack->b = malloc(sizeof(char *) * (stack_len(stack->a) + 1));
	if (stack->b == NULL)
		return (0);
	i = -1;
	while (++i <= stack_len(stack->a))
		stack->b[i] = NULL;
	return (1);
}

int		manage_orders(char **orders, t_stack *stack)
{
	int i;
	int ret;

	i = -1;
	orders = NULL;
	orders = ft_realloc_double(orders);
	while ((ret = get_next_line(0, &orders[++i])) > 0)
	{
		if (!(execute_orders(stack, orders[i])))
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
