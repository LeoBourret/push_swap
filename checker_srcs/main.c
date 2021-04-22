/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:52:52 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/22 17:11:43 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(t_stack *stack, int verbose)
{
	char	**orders;
	int		i;
	int		ret;

	orders = NULL;
	ret = manage_orders(orders, stack, verbose);
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
	int			offset;
	int			verbose;

	offset = 1;
	verbose = 0;
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if ((ft_strcmp(av[1], "-v")) == 0)
	{
		offset = 2;
		verbose = 1;
	}
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_printf("Error malloc\n");
		return (0);
	}
	if (!(set_stack(av + offset, stack)))
		return (0);
	checker(stack, verbose);
	free_stack(stack);
	return (0);
}
