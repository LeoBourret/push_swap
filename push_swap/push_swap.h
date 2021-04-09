/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:43:00 by lebourre          #+#    #+#             */
/*   Updated: 2021/04/09 17:04:55 by lebourre         ###   ########.fr       */
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

int				ft_ispace(char c);
int				execute_orders(t_stack *stack, char **orders);
int				solve_three(char **stack, int c);
void			solve_three_reverse(char **stack, int c);
int				solve_four_five(t_stack *stack);
int				solve_ten(t_stack *stack);
void			solve_hundred(t_stack *stack, int size_chunck, int *chunck);
int				is_sorted(char **stack);
int				is_sorted_reverse(char **stack);
int				is_in_tab(int *tab, int value, int size);
int				find_min(char **stack);
int				find_max(char **stack);
int				stack_len(char **stack);
int				is_in_tab(int *tab, int value, int size);
int				skip_space(char *s);
int				skip_digit(char *s);
int				check_str(char *av);
int				check_args(char **av);
int				insertion_place_reverse(char **stack, int value);
void			set_closest_top_min_on_top(char **stack, int front, int back);
void			push_correct_order(t_stack *stack, int max, int min, int size);
void			push_a_elem_to_b_reverse_sort(t_stack *stack, int min, int max);
void			swap(char **stack, int c);
void			push(char **stack_dest, char **stack_src, int c);
void			rotate(char **stack, int c);
void			reverse_rotate(char **stack, int c);
void			print_stack(char **stack1, char **stack2);

#endif
