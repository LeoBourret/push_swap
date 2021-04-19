/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:53:15 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/19 15:12:04 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H_
# define _CHECKER_H_

# include "../libft/libft.h"

typedef	struct	s_stack
{
	char	**a;
	char	**b;
}				t_stack;

int			execute_orders(t_stack *t_stack, char **orders);
int			get_next_line(int fd, char **lines);
void		print_stack(char **stack1, char **stack2);
void		reverse_rotate(char **stack);
void		rotate(char **stack);
void		push(char **stack_dest, char **stack_src);
void		swap(char **stack);

#endif
