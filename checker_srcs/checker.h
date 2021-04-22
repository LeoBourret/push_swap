/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:53:15 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/22 17:14:49 by lebourre         ###   ########.fr       */
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

typedef	struct	s_options
{
	int		offset;
	int		verbose;
}				t_options;

int			manage_orders(char **orders, t_stack *stack, int verbose);
int			set_stack(char **av, t_stack *stack);
int			check_args(char **av);
int			stack_len(char **stack);
int			execute_orders(t_stack *t_stack, char *orders, int verbose);
int			get_next_line(int fd, char **lines);
void		print_stack(char **stack1, char **stack2);
void		reverse_rotate(char **stack);
void		rotate(char **stack);
void		push(char **stack_dest, char **stack_src);
void		swap(char **stack);
void		free_stack(t_stack *stack);
void		free_orders(char **orders);
char		*join_args(char **av);
int			ft_ispace(char c);
int			skip_space(char *s);
int			skip_digit(char *s);

#endif
