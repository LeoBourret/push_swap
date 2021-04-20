/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:11:09 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/20 16:33:48 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(char **stack1, char **stack2)
{
	if (stack1 && *stack1)
	{
		ft_printf("stack A = ");
		while (*stack1)
			ft_printf("%s ", *(stack1++));
		ft_printf("\n");
	}
	if (stack2 && *stack2)
	{
		ft_printf("stack B = ");
		while (*stack2)
			ft_printf("%s ", *(stack2++));
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	swap(char **stack)
{
	char *swap;

	if (stack[0] == NULL || stack[1] == NULL)
		return ;
	swap = stack[0];
	stack[0] = stack[1];
	stack[1] = swap;
}

void	push(char **stack_dest, char **stack_src)
{
	int		i;

	i = 0;
	if (!*stack_src)
		return ;
	while (stack_dest[i])
		i++;
	while (i > 0)
	{
		free(stack_dest[i]);
		stack_dest[i] = ft_strdup(stack_dest[i - 1]);
		i--;
	}
	free(stack_dest[0]);
	stack_dest[0] = ft_strdup(stack_src[0]);
	while (stack_src[i + 1])
	{
		free(stack_src[i]);
		stack_src[i] = ft_strdup(stack_src[i + 1]);
		i++;
	}
	free(stack_src[i]);
	stack_src[i] = NULL;
}

void	rotate(char **stack)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*stack)
		return ;
	while (stack[i + 1])
		i++;
	tmp = ft_strdup(stack[i]);
	free(stack[i]);
	stack[i] = ft_strdup(stack[0]);
	i = 0;
	while (stack[i + 2])
	{
		free(stack[i]);
		stack[i] = ft_strdup(stack[i + 1]);
		i++;
	}
	free(stack[i]);
	stack[i] = tmp;
}

void	reverse_rotate(char **stack)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*stack)
		return ;
	while (stack[i + 1])
		i++;
	tmp = ft_strdup(stack[0]);
	free(stack[0]);
	stack[0] = ft_strdup(stack[i]);
	while (i > 1)
	{
		free(stack[i]);
		stack[i] = ft_strdup(stack[i - 1]);
		i--;
	}
	free(stack[i]);
	stack[i] = tmp;
}
