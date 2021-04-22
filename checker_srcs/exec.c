/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:13:03 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/22 17:11:24 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		execute_orders_3(t_stack *stack, char *orders)
{
	if ((ft_strcmp(orders, "pa")) == 0)
		push(stack->a, stack->b);
	else if ((ft_strcmp(orders, "pb")) == 0)
		push(stack->b, stack->a);
	else
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	return (1);
}

int		execute_orders_2(t_stack *stack, char *orders)
{
	if ((ft_strcmp(orders, "ra")) == 0)
		rotate(stack->a);
	else if ((ft_strcmp(orders, "rb")) == 0)
		rotate(stack->b);
	else if ((ft_strcmp(orders, "rr")) == 0)
	{
		rotate(stack->a);
		rotate(stack->b);
	}
	else if ((ft_strcmp(orders, "rra")) == 0)
		reverse_rotate(stack->a);
	else if ((ft_strcmp(orders, "rrb")) == 0)
		reverse_rotate(stack->b);
	else if ((ft_strcmp(orders, "rrr")) == 0)
	{
		reverse_rotate(stack->a);
		reverse_rotate(stack->b);
	}
	else
	{
		if ((execute_orders_3(stack, orders)) == 0)
			return (0);
	}
	return (1);
}

int		execute_orders(t_stack *stack, char *orders, int verbose)
{
	if ((ft_strcmp(orders, "sa")) == 0)
		swap(stack->a);
	else if ((ft_strcmp(orders, "sb")) == 0)
		swap(stack->b);
	else if ((ft_strcmp(orders, "ss")) == 0)
	{
		swap(stack->a);
		swap(stack->b);
	}
	else
	{
		if ((execute_orders_2(stack, orders)) == 0)
			return (0);
	}
	if (verbose == 1)
		print_stack(stack->a, stack->b);
	return (1);
}
