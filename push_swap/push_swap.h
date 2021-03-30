#ifndef _CHECKER_H_
# define _CHECKER_H_

# include "../libft/libft.h"

typedef	struct	s_stack
{
	char	**a;
	char	**b;
}				t_stack;

int			execute_orders(t_stack *t_stack, char **orders);
int			solve_three(char	**stack);
int			solve_four_five(t_stack *t_stack);
int			is_sorted(char **stack);
void		swap(char **stack);
void		push(char **stack_dest, char **stack_src);
void		rotate(char **stack);
void		reverse_rotate(char **stack);
void		print_stack(char **stack1, char **stack2);

#endif
