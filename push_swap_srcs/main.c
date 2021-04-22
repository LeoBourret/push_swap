/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:39:30 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/22 17:57:02 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_stack(char **av, t_stack *stack)
{
	int		i;
	char	*args;

	args = join_args(av);
	if (!check_str(args))
	{
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

void	launch_solver(int stack_len, t_stack *stack, t_options *options)
{
	if (stack_len == 2)
	{
		if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[1]))
			swap(stack->a, 0, stack, options);
	}
	else if (stack_len == 3)
		solve_three(stack->a, 0);
	else if (stack_len >= 4 && stack_len <= 5)
		solve_four_five(stack, stack_len, options);
	else if (stack_len >= 6 && stack_len <= 10)
		solve_ten(stack);
	else if (stack_len > 10 && stack_len <= 30)
		solve_hundred(stack, 8, 0);
	else if (stack_len > 30 && stack_len < 100)
		solve_hundred(stack, 15, 0);
	else if (stack_len >= 100 && stack_len <= 300)
		solve_hundred(stack, 20, 0);
	else if (stack_len >= 300 && stack_len <= 700)
		solve_hundred(stack, 72, 0);
	else if (stack_len > 700)
		solve_hundred(stack, 80, 0);
	print_stack(stack->a, stack->b);
}

int		check_settings(int ac, char **av, t_options *options, t_stack *stack)
{
	if (stack == NULL || options == NULL)
	{
		ft_printf("malloc error\n");
		return (0);
	}
	else if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (ac >= 2)
	{
		if (!(set_stack(av + options->offset, stack)))
		{
			ft_printf("Error\n");
			free_stack(stack);
			return (0);
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack *stack;
	t_options *options;

	options = malloc(sizeof(options));
	stack = malloc(sizeof(stack));
	set_options(options, av);
	if (!check_settings(ac, av, options, stack))
		return (1);
	launch_solver(stack_len(stack->a), stack, options);
	free_stack(stack);
	return (0);
}
