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
	ft_printf("| ");
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

void	swap(char **stack)
{
	char *swap;

	if (stack[0] == NULL || stack[1] == NULL)
		return ;
	swap = stack[0];
	stack[0] = stack[1];
	stack[1] = swap;
}

void	push(char **stack_dest, char **stack_src)
{
	int		i;

	i = 0;
	if (!*stack_src)
		return ;
	while (stack_dest[i])
		i++;
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
}

void	rotate(char **stack)
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
}

void	reverse_rotate(char **stack)
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
}

int		execute_orders(t_stack *t_stack, char **orders)
{
	int		i;

	i = -1;
	i = 0;
	while (orders[i] != NULL)
	{
		if ((ft_strncmp(orders[i], "sa", ft_strlen(orders[i]))) == 0)
			swap(t_stack->a);
		else if ((ft_strncmp(orders[i], "sb", ft_strlen(orders[i]))) == 0)
			swap(t_stack->b);
		else if ((ft_strncmp(orders[i], "ss", ft_strlen(orders[i]))) == 0)
		{
			swap(t_stack->a);
			swap(t_stack->b);
		}
		else if ((ft_strncmp(orders[i], "pa", ft_strlen(orders[i]))) == 0)
			push(t_stack->a, t_stack->b);
		else if ((ft_strncmp(orders[i], "pb", ft_strlen(orders[i]))) == 0)
			push(t_stack->b, t_stack->a);
		else if ((ft_strncmp(orders[i], "ra", ft_strlen(orders[i]))) == 0)
			rotate(t_stack->a);
		else if ((ft_strncmp(orders[i], "rb", ft_strlen(orders[i]))) == 0)
			rotate(t_stack->b);
		else if ((ft_strncmp(orders[i], "rr", ft_strlen(orders[i]))) == 0)
		{
			rotate(t_stack->a);
			rotate(t_stack->b);
		}
		else if ((ft_strncmp(orders[i], "rra", ft_strlen(orders[i]))) == 0)
			reverse_rotate(t_stack->a);
		else if ((ft_strncmp(orders[i], "rrb", ft_strlen(orders[i]))) == 0)
			reverse_rotate(t_stack->b);
		else if ((ft_strncmp(orders[i], "rrr", ft_strlen(orders[i]))) == 0)
		{
			reverse_rotate(t_stack->a);
			reverse_rotate(t_stack->b);
		}
		else
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		print_stack(t_stack->a, t_stack->b);
		i++;
	}
	return (1);
}
