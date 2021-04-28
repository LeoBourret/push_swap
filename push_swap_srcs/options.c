/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:20:38 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/28 14:45:55 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_option(char c)
{
	if (c == 'v')
		return (1);
	return (0);
}

int		check_arg(char *s, t_options *options)
{
	if (s == NULL || *s != '-')
		return (0);
	s++;
	while (is_option(*s))
	{
		if (*s == 'v')
			options->verbose = 1;
		s++;
	}
	if (*s != '\0')
		return (0);
	return (1);
}

void	init_options(t_options *options)
{
	options->offset = 1;
	options->verbose = 0;
}

void	set_options(t_options *options, char **av)
{
	init_options(options);
	while (check_arg(av[options->offset], options))
		options->offset++;
}
