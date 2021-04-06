#include "push_swap.h"

void	print_stack(char **stack1, char **stack2)
{
	if (stack1 && *stack1)
	{
		ft_printf("stack A = |");
		while (*stack1)
		{
			if (*(stack1 + 1))
				ft_printf("%s ", *(stack1++));
			else
				ft_printf("%s", *(stack1++));
		}
	ft_printf("|\n");
	}
	if (stack2 && *stack2)
	{
		ft_printf("stack B = |");
		while (*stack2)
		{
			if (*(stack2 + 1))
				ft_printf("%s ", *(stack2++));
			else
				ft_printf("%s", *(stack2++));
		}
		ft_printf("|");
	}
	ft_printf("\n");
}

void	swap(char **stack, int c)
{
	char *swap;

	if (stack[0] == NULL || stack[1] == NULL)
		return ;
	swap = stack[0];
	stack[0] = stack[1];
	stack[1] = swap;
	if (c == 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	push(char **stack_dest, char **stack_src, int c)
{
	int		i;

	i = 0;
	i = stack_len(stack_dest);
	while (i > 0)
	{
		free(stack_dest[i]);
		stack_dest[i] = ft_strdup(stack_dest[i - 1]);
		i--;
	}
	free(stack_dest[0]);
	stack_dest[0] = ft_strdup(stack_src[0]);
	while (stack_src[i + 1])
	{
		free(stack_src[i]);
		stack_src[i] = ft_strdup(stack_src[i + 1]);
		i++;
	}
	free(stack_src[i]);
	stack_src[i] = NULL;
	if (c == 0)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rotate(char **stack, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*stack)
		return ;
	while (stack[i + 1])
		i++;
	tmp = ft_strdup(stack[i]);
	free(stack[i]);
	stack[i] = ft_strdup(stack[0]);
	i = 0;
	while (stack[i + 2])
	{
		free(stack[i]);
		stack[i] = ft_strdup(stack[i + 1]);
		i++;
	}
	free(stack[i]);
	stack[i] = tmp;
	if (c == 0)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	reverse_rotate(char **stack, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*stack)
		return ;
	while (stack[i + 1])
		i++;
	tmp = ft_strdup(stack[0]);
	free(stack[0]);
	stack[0] = ft_strdup(stack[i]);
	while (i > 1)
	{
		free(stack[i]);
		stack[i] = ft_strdup(stack[i - 1]);
		i--;
	}
	free(stack[i]);
	stack[i] = tmp;
	if (c == 0)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
