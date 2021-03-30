#include "push_swap.h"

int		check_args(char **av)
{
	int		i;
	int		j;
	int		index;
	long	value;
	char	*ptr;

	i = -1;
	while (av[++i])
	{
		index = -1;
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (0);
		value = ft_atoi(av[i]);
		if (value > 2147483647 || value < -2147483648)
			return (0);
		while (++index < i)
		{
			ptr = av[index];
			if (ft_atoi(ptr) == ft_atoi(av[i]))
				return (0);
		}
	}
	return (1);
}

int		set_stack(int ac, char **av, t_stack *t_stack)
{
	int i;

	i = -1;
	t_stack->a = malloc(sizeof(char *) * (ac + 1));
	t_stack->b = malloc(sizeof(char *) * (ac + 1));
	if (t_stack->a == NULL || t_stack->b == NULL)
		return (0);
	while (av[++i])
		t_stack->a[i] = ft_strdup(av[i]);
	t_stack->a[i] = NULL;
	i = -1;
	while (++i <= ac)
		t_stack->b[i] = NULL;
	return (1);
}

void	checker(int ac, char **av, t_stack *t_stack)
{
	set_stack(ac, av, t_stack);
	print_stack(t_stack->a, t_stack->b);
	if (ac == 3)
		solve_three(t_stack->a);
	else if (ac >= 4 && ac <= 5)
		solve_four_five(t_stack);
}

int		main(int ac, char **av)
{
	t_stack *t_stack;

	if (ac < 2 || !check_args(av + 1))
	{
		ft_printf("Error\n");
		return (0);
	}
	t_stack = malloc(sizeof(t_stack));
	if (t_stack == NULL)
		return (0);
	checker(ac - 1, av + 1, t_stack);
	return (0);
}
