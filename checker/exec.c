/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:13:03 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/19 17:20:39 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		execute_orders_3(t_stack *stack, char **orders, int i)
{
	if ((ft_strncmp(orders[i], "pa", ft_strlen(orders[i]))) == 0)
		push(stack->a, stack->b);
	else if ((ft_strncmp(orders[i], "pb", ft_strlen(orders[i]))) == 0)
		push(stack->b, stack->a);
	else
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	return (1);
}

int		execute_orders_2(t_stack *stack, char **orders, int i)
{
	if ((ft_strncmp(orders[i], "ra", ft_strlen(orders[i]))) == 0)
		rotate(stack->a);
	else if ((ft_strncmp(orders[i], "rb", ft_strlen(orders[i]))) == 0)
		rotate(stack->b);
	else if ((ft_strncmp(orders[i], "rr", ft_strlen(orders[i]))) == 0)
	{
		rotate(stack->a);
		rotate(stack->b);
	}
	else if ((ft_strncmp(orders[i], "rra", ft_strlen(orders[i]))) == 0)
		reverse_rotate(stack->a);
	else if ((ft_strncmp(orders[i], "rrb", ft_strlen(orders[i]))) == 0)
		reverse_rotate(stack->b);
	else if ((ft_strncmp(orders[i], "rrr", ft_strlen(orders[i]))) == 0)
	{
		reverse_rotate(stack->a);
		reverse_rotate(stack->b);
	}
	else
	{
		if ((execute_orders_3(stack, orders, i)) == 0)
			return (0);
	}
	return (1);
}

int		execute_orders(t_stack *stack, char **orders)
{
	int		i;

	i = -1;
	i = 0;
	while (orders[i] != NULL)
	{
		if ((ft_strncmp(orders[i], "sa", ft_strlen(orders[i]))) == 0)
			swap(stack->a);
		else if ((ft_strncmp(orders[i], "sb", ft_strlen(orders[i]))) == 0)
			swap(stack->b);
		else if ((ft_strncmp(orders[i], "ss", ft_strlen(orders[i]))) == 0)
		{
			swap(stack->a);
			swap(stack->b);
		}
		else
		{
			if ((execute_orders_2(stack, orders, i)) == 0)
				return (0);
		}
		i++;
		print_stack(stack->a, stack->b);
	}
	return (1);
}
