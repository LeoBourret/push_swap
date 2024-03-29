/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:48:57 by lebourre          #+#    #+#             */
/*   Updated: 2021/05/17 15:19:07 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*cat_space(char *s)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(s) - 1;
	while (len > 0 && s[len] == ' ')
		len--;
	ret = malloc(sizeof(char) * len + 1);
	i = -1;
	while (++i <= len)
		ret[i] = s[i];
	ret[i] = '\0';
	free(s);
	return (ret);
}

char	*join_args(char **av)
{
	int		i;
	char	*tmp;
	char	*new;

	i = -1;
	tmp = malloc(sizeof(char) * (ft_strlen(av[0]) + 2));
	while (av[0][++i])
		tmp[i] = av[0][i];
	tmp[i] = ' ';
	tmp[i + 1] = '\0';
	i = 0;
	while (av[++i])
	{
		new = ft_strjoin(tmp, av[i]);
		new = ft_realloc(new, ft_strlen(new) + 2);
		new[ft_strlen(new)] = ' ';
		new[ft_strlen(new)] = '\0';
		free(tmp);
		tmp = ft_strdup(new);
		free(new);
	}
	new = ft_strdup(tmp);
	free(tmp);
	return (cat_space(new));
}

void	push_min(t_stack *stack, int nb_of_push)
{
	int i;
	int min;

	while (nb_of_push != 0)
	{
		min = find_min(stack->a);
		i = 0;
		while (ft_atoi(stack->a[i]) != min)
			i++;
		set_value_to_top(stack->a, i, 0, stack_len(stack->a) % 2);
		push_a_to_b_reverse_sort(stack, 0, 0);
		nb_of_push--;
	}
}

void	fix_stack(char **stack)
{
	int i;

	if (!is_sorted_reverse(stack))
	{
		i = -1;
		while (stack[++i])
			if (ft_atoi(stack[i]) < ft_atoi(stack[i + 1]))
			{
				i++;
				break ;
			}
		if (i > (stack_len(stack) / 2))
		{
			while (!is_sorted_reverse(stack))
				reverse_rotate(stack, 1);
		}
		else
			while (!is_sorted_reverse(stack))
				rotate(stack, 1);
	}
}
