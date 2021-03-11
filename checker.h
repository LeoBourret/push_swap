/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:53:15 by lebourre          #+#    #+#             */
/*   Updated: 2021/03/11 16:37:43 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H_
# define _CHECKER_H_

# include "libft/libft.h"

typedef	struct	s_stack
{
	int		*a;
	int		*b;
}				t_stack;

int			get_next_line(int fd, char **lines);

#endif
