/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:39:30 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/13 18:07:16 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (0);
	stack->b = malloc(sizeof(char *) * (stack_len(stack->a) + 1));
	if (stack->b == NULL)
		return (0);
	i = -1;
	while (++i <= stack_len(stack->a))
		stack->b[i] = NULL;
	return (1);
}

void	checker(int stack_len, t_stack *stack)
{
	print_stack(stack->a, stack->b);
	if (stack_len == 3)
		solve_three(stack->a, 0);
	else if (stack_len >= 4 && stack_len <= 5)
		solve_four_five(stack, stack_len);
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
}

/*
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
*/
int		main(int ac, char **av)
{
	t_stack *stack;

	stack = malloc(sizeof(stack));
	if (stack == NULL)
		return (1);
	else if (ac < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (ac >= 2)
	{
		if (!(set_stack(av + 1, stack)))
		{
			ft_printf("Error\n");
			free_stack(stack);
			return (1);
		}
	}
	free_stack(stack);
	while (1)
		;
	checker(stack_len(stack->a), stack);
	free_stack(stack);
	while (1)
		;
	return (0);
}
