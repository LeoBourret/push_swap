#include "push_swap.h"

int		*get_chunck(int *tab, int *size, char **stack)
{
	int min;
	int max;
	int i;
	int j;

	min = find_min(stack);
	max = find_max(stack);
	if (*size > stack_len(stack))
		*size = stack_len(stack);
	tab = malloc(sizeof(int) * *size);
	if (!tab)
		return (0);
	i = -1;
	while (++i < *size)
		tab[i] = min;
	i = 0;
	while (++i < *size)
	{
		min = max;
		j = -1;
		while (stack[++j])
			if (min > ft_atoi(stack[j])
			&& !is_in_tab(tab, ft_atoi(stack[j]), *size))
				min = ft_atoi(stack[j]);
		tab[i] = min;
	}
	return (tab);
}

void	push_back(t_stack *t_stack)
{
	int i;

	if (!is_sorted_reverse(t_stack->b))
	{
		i = -1;
		while (t_stack->b[++i])
			if (ft_atoi(t_stack->b[i]) < ft_atoi(t_stack->b[i + 1]))
			{
				i++;
				break ;
			}
		if (i > (stack_len(t_stack->b) / 2))
		{
			while (!is_sorted_reverse(t_stack->b))
				reverse_rotate(t_stack->b, 1);
		}
		else
			while (!is_sorted_reverse(t_stack->b))
				rotate(t_stack->b, 1);
	}
	while (stack_len(t_stack->b))
		push(t_stack->a, t_stack->b, 0);
}

void	solve_hundred(t_stack *t_stack, int size_chunck)
{
	int *chunck;
	int i;
	int j;
	int index;

	if (stack_len(t_stack->a) == 0)
	{
		push_back(t_stack);
		print_stack(t_stack->a, t_stack->b);
		return ;
	}
	chunck = get_chunck(chunck, &size_chunck, t_stack->a);
	index = -1;
	while (++index < size_chunck)
	{
		i = 0;
		j = stack_len(t_stack->a) - 1;
		while (!is_in_tab(chunck, ft_atoi(t_stack->a[i]), size_chunck))
			i++;
		while (!is_in_tab(chunck, ft_atoi(t_stack->a[j]), size_chunck))
			j--;
		j = (j - stack_len(t_stack->a)) * -1;
		set_closest_top_min_on_top(t_stack->a, i, j);
		if (stack_len(t_stack->b) == 0 || stack_len(t_stack->b) == 1)
			push(t_stack->b, t_stack->a, 1);
		else
			push_a_elem_to_b_reverse_sort(t_stack, 0, 0);
	}
	free(chunck);
	solve_hundred(t_stack, size_chunck);
}
