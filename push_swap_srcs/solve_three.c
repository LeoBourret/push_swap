/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:51:32 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/28 14:54:03 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three_reverse_2(char **stack, int c, t_stack *stk, t_options *opt)
{
	if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		reverse_rotate(stack, c, stk, opt);
		return ;
	}
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		swap(stack, c, stk, opt);
		return ;
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		reverse_rotate(stack, c, stk, opt);
		swap(stack, c, stk, opt);
		return ;
	}
}

void	solve_three_reverse(char **stack, int c, t_stack *stk, t_options *opt)
{
	if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2]))
	{
		return ;
	}
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		rotate(stack, c, stk, opt);
		swap(stack, c, stk, opt);
		return ;
	}
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		rotate(stack, c, stk, opt);
		return ;
	}
	solve_three_reverse_2(stack, c, stk, opt);
}

void	solve_three_2(char **stack, int c, t_stack *stk, t_options *opt)
{
	if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		reverse_rotate(stack, c, stk, opt);
		return ;
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		rotate(stack, c, stk, opt);
		return ;
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) > ft_atoi(stack[2]))
	{
		swap(stack, c, stk, opt);
		reverse_rotate(stack, c, stk, opt);
		return ;
	}
}

int		solve_three(char **stack, int c, t_stack *stk, t_options *opt)
{
	if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2]))
		return (1);
	else if (ft_atoi(stack[0]) < ft_atoi(stack[1])
	&& ft_atoi(stack[1]) > ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		swap(stack, c, stk, opt);
		rotate(stack, c, stk, opt);
		return (1);
	}
	else if (ft_atoi(stack[0]) > ft_atoi(stack[1])
	&& ft_atoi(stack[1]) < ft_atoi(stack[2])
	&& ft_atoi(stack[0]) < ft_atoi(stack[2]))
	{
		swap(stack, c, stk, opt);
		return (1);
	}
	else
		solve_three_2(stack, c, stk, opt);
	return (1);
}
