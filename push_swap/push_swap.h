#ifndef _PUSH_SWAP_H_
# define _PUSH_SWAP_H_

# include "../libft/libft.h"

typedef	struct	s_stack
{
	char	**a;
	char	**b;
}				t_stack;

int			execute_orders(t_stack *t_stack, char **orders);
int			solve_three(char **stack, int c);
void		solve_three_reverse(char **stack, int c);
int			solve_four_five(t_stack *t_stack);
int			solve_ten(t_stack *t_stack);
int			is_sorted(char **stack);
int			is_sorted_reverse(char **stack);
int			find_min(char **stack);
int			find_max(char **stack);
int			stack_len(char **stack);
void		swap(char **stack, int c);
void		push(char **stack_dest, char **stack_src, int c);
void		rotate(char **stack, int c);
void		reverse_rotate(char **stack, int c);
void		print_stack(char **stack1, char **stack2);

#endif
