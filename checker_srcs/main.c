/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:52:52 by lebourre          #+#    #+#             */
/*   Updated: 2021/05/16 16:58:08 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(t_stack *stack)
{
	char	**orders;
	int		i;
	int		ret;

	orders = NULL;
	ret = manage_orders(orders, stack);
	if (ret < 0)
		return ;
	i = 0;
	while (stack->a[i + 1])
	{
		if (ft_atoi(stack->a[i]) > ft_atoi(stack->a[i + 1])
		|| stack_len(stack->b) > 0)
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
	t_stack		*stack;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_printf("Error malloc\n");
		return (0);
	}
	if (!(set_stack(av + 1, stack)))
		return (0);
	checker(stack);
	free_stack(stack);
	return (0);
}
