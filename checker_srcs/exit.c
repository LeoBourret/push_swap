/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:48:02 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/20 16:38:18 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_orders(char **orders)
{
	int i;

	if (orders)
	{
		i = -1;
		while (orders[++i])
			free(orders[i]);
		free(orders);
	}
}

void	free_stack(t_stack *stack)
{
	int i;

	i = -1;
	if (stack->a)
	{
		while (stack->a[++i])
			free(stack->a[i]);
		free(stack->a);
	}
	i = -1;
	if (stack->b)
	{
		while (stack->b[++i])
			free(stack->b[i]);
		free(stack->b);
	}
	free(stack);
}
