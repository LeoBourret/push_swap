#ifndef _PUSH_SWAP_H_
# define _PUSH_SWAP_H_

# include "../libft/libft.h"

typedef	struct	s_stack
{
	char	**a;
	char	**b;
}				t_stack;

int			ft_ispace(char c);
int			execute_orders(t_stack *t_stack, char **orders);
int			solve_three(char **stack, int c);
void		solve_three_reverse(char **stack, int c);
int			solve_four_five(t_stack *t_stack);
int			solve_ten(t_stack *t_stack);
void		solve_hundred(t_stack *t_stack, int size_chunck);
int			is_sorted(char **stack);
int			is_sorted_reverse(char **stack);
int			find_min(char **stack);
int			find_max(char **stack);
int			stack_len(char **stack);
int			is_in_tab(int *tab, int value, int size);
int			insertion_place_reverse(char **stack, int value);
void		set_closest_top_min_on_top(char **stack, int front, int back);
void		push_correct_order(t_stack *t_stack, int max, int min, int size);
void		push_a_elem_to_b_reverse_sort(t_stack *t_stack, int min, int max);
void		swap(char **stack, int c);
void		push(char **stack_dest, char **stack_src, int c);
void		rotate(char **stack, int c);
void		reverse_rotate(char **stack, int c);
void		print_stack(char **stack1, char **stack2);

#endif
