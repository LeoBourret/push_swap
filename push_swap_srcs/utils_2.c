/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:28:23 by lebourre          #+#    #+#             */
/*   Updated: 2021/05/16 15:39:36 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		skip_space(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_ispace(s[i]))
		i++;
	return (i);
}

int		skip_digit(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	return (i);
}

int		ft_ispace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int		find_max(char **stack)
{
	int i;
	int max_value;

	i = -1;
	max_value = ft_atoi(stack[0]);
	while (stack[++i])
	{
		if (ft_atoi(stack[i]) > max_value)
			max_value = ft_atoi(stack[i]);
	}
	return (max_value);
}

int		stack_len(char **stack)
{
	int i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}
