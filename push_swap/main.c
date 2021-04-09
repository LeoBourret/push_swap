/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:39:30 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/09 16:56:49 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_stack_from_var(int ac, char *av, t_stack *stack)
{
	int i;
	int index;

	i = 0;
	index = 0;
	stack->a = malloc(sizeof(char *) * (ac + 1));
	stack->b = malloc(sizeof(char *) * (ac + 1));
	if (stack->a == NULL || stack->b == NULL)
		return (0);
	while (av[i])
	{
		stack->a[index] = ft_itoa(ft_atoi(&av[i]));
		i += skip_space(&av[i]);
		i += skip_digit(&av[i]);
		index++;
	}
	stack->a[i] = NULL;
	i = -1;
	while (++i <= ac)
		stack->b[i] = NULL;
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

void	checker(int ac, t_stack *stack)
{
	print_stack(stack->a, stack->b);
	if (ac == 3)
		solve_three(stack->a, 0);
	else if (ac >= 4 && ac <= 5)
		solve_four_five(stack);
	else if (ac >= 6 && ac <= 10)
		solve_ten(stack);
	else if (ac > 10 && ac <= 30)
		solve_hundred(stack, 8, 0);
	else if (ac > 30 && ac < 100)
		solve_hundred(stack, 15, 0);
	else if (ac >= 100 && ac <= 300)
		solve_hundred(stack, 20, 0);
	else if (ac >= 300 && ac <= 700)
		solve_hundred(stack, 72, 0);
	else if (ac > 700)
		solve_hundred(stack, 80, 0);
}

int		list_size(char *s)
{
	int count;
	int i;

	i = 0;
	count = 1;
	while (s[i])
	{
		i += skip_space(&s[i]);
		i += skip_digit(&s[i]);
		count++;
	}
	return (count);
}

int		main(int ac, char **av)
{
	t_stack *stack;

	stack = malloc(sizeof(stack));
	if (stack == NULL)
		return (0);
	if (ac == 2)
	{
		if (!check_str(av[1]))
		{
			ft_printf("Error\n");
			return (0);
		}
		ac = list_size(av[1]);
		set_stack_from_var(ac - 1, *(av + 1), stack);
	}
	else if (ac < 2 || !check_args(av + 1))
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (ac > 2)
		set_stack(ac - 1, av + 1, stack);
	checker(ac - 1, stack);
	return (0);
}
