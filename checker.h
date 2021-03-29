/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:53:15 by lebourre          #+#    #+#             */
/*   Updated: 2021/03/29 14:44:09 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H_
# define _CHECKER_H_

# include "libft/libft.h"

typedef	struct	s_stack
{
	char	**a;
	char	**b;
}				t_stack;

int			execute_orders(t_stack *t_stack, char **orders);
int			get_next_line(int fd, char **lines);
void		print_stack(char **stack1, char **stack2);

#endif
