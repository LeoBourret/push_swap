/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:21:56 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/12 17:24:41 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
