/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:42:24 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/12 17:40:49 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int buffer_size)
{
	char	*new;
	int		i;

	if (!str)
	{
		if (!(new = malloc(sizeof(char) * (buffer_size + 1))))
			return (NULL);
		return (new);
	}
	if (!(new = malloc(sizeof(char *) * (ft_strlen(str) + buffer_size + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = '\0';
	new[i + 1] = '\0';
	free(str);
	str = NULL;
	return (new);
}
