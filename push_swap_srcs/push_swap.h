/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:43:00 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/28 15:31:10 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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


int				ft_ispace(char c);
char			*join_args(char **av);
void			fix_stack(char **stack, t_stack *stk, t_options *opt);
int				execute_orders(t_stack *stack, char **orders);
//void			set_value_to_top(char **stack, int index, int c, int odd);
int				solve_three(char **stack, int c, t_stack *stk, t_options *opt);
void			solve_three_reverse(char **s, int c, t_stack *st, t_options *o);
int				solve_four_five(t_stack *stack, int stack_size, t_options *opt);
int				solve_ten(t_stack *stack, t_options *options);
void			solve_hundred(t_stack *stack, int size_chunck, int *chunck,
t_options *options);
int				is_sorted(char **stack);
int				*get_chunck(int *tab, int *size, char **stack, int i);
int				is_sorted_reverse(char **stack);
int				is_in_tab(int *tab, int value, int size);
void			push_closest_min(t_stack *stack, int stack_size, int *chunck,
t_options *opt);
void			push_min(t_stack *stack, int nb_of_push, t_options *opt);
int				find_min(char **stack);
int				find_max(char **stack);
int				stack_len(char **stack);
int				is_in_tab(int *tab, int value, int size);
int				skip_space(char *s);
int				skip_digit(char *s);
int				check_str(char *av);
int				check_args(char **av);
int				insertion_place_reverse(char **stack, int value);
void			set_closest_top_min_on_top(char **stack, int distance,
t_stack *stk, t_options *options);
void			push_correct_order(t_stack *stack, int max, int min, int size);
void			push_a_to_b_reverse_sort(t_stack *stk, int min, int max,
t_options *opt);
void			swap(char **stack, int c, t_stack *stc, t_options *options);
void			push(char **dest, char **src, int c, t_options *options);
void			rotate(char **stack, int c, t_stack *stck, t_options *options);
void			reverse_rotate(char **s, int c, t_stack *stck, t_options *o);
void			print_stack(char **stack1, char **stack2);
void			free_stack(t_stack *stack);
void			set_options(t_options *options, char **av);

#endif
