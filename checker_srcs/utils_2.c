/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:03:13 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/22 17:07:21 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	return (new);
}

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
