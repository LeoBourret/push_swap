#include "push_swap.h"

int		check_str(char *av)
{
	int		i;
	int		index;

	i = -1;
	while (av[++i])
			if (!ft_isdigit(av[i]) && !ft_ispace(av[i]))
				return (0);
	i = 0;
	while (av[i])
	{
		index = -1;
		if (ft_atoi(&av[i]) > 2147483647 || ft_atoi(&av[i]) < -2147483648)
			return (0);
		while (++index < i)
		{
			if (ft_atoi(&av[index]) == ft_atoi(&av[i]))
				return (0);
			index += skip_space(&av[index]);
			index += skip_digit(&av[index]);
		}
		i += skip_space(&av[i]);
		i += skip_digit(&av[i]);
	}
	return (1);
}


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

int		set_stack_from_var(int ac, char *av, t_stack *t_stack)
{
	int i;
	int index;

	i = 0;
	index = 0;
	t_stack->a = malloc(sizeof(char *) * (ac + 1));
	t_stack->b = malloc(sizeof(char *) * (ac + 1));
	if (t_stack->a == NULL || t_stack->b == NULL)
		return (0);
	while (av[i])
	{
		t_stack->a[index] = ft_itoa(ft_atoi(&av[i]));
		i += skip_space(&av[i]);
		i += skip_digit(&av[i]);
		index++;
	}
	t_stack->a[i] = NULL;
	i = -1;
	while (++i <= ac)
		t_stack->b[i] = NULL;
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

void	checker(int ac, t_stack *t_stack)
{
	print_stack(t_stack->a, t_stack->b);
	if (ac == 3)
		solve_three(t_stack->a, 0);
	else if (ac >= 4 && ac <= 5)
		solve_four_five(t_stack);
	else if (ac >= 6 && ac <= 10)
		solve_ten(t_stack);
	else if (ac > 10 && ac <= 30)
		solve_hundred(t_stack, 8);\
	else if (ac > 30 && ac < 100)
		solve_hundred(t_stack, 15);
	else if (ac >= 100 && ac <= 300)
		solve_hundred(t_stack, 20);
	else if (ac >= 300 && ac <= 700)
		solve_hundred(t_stack, 72);
	else if (ac > 700)
		solve_hundred(t_stack, 80);
}

int		list_size(char *s)
{
	int count;
	int i;

	i = 0;
	count = 1;
	while (s[i])
	{
		i += skip_space(&s[i]);
		i += skip_digit(&s[i]);
		count++;
	}
	return (count);
}

int		main(int ac, char **av)
{
	t_stack *t_stack;

	t_stack = malloc(sizeof(t_stack));
	if (t_stack == NULL)
		return (0);
	if (ac == 2)
	{
		if (!check_str(av[1]))
		{
			ft_printf("Error\n");
			return (0);
		}
		ac = list_size(av[1]);
		set_stack_from_var(ac - 1, *(av + 1), t_stack);
	}
	else if (ac < 2 || !check_args(av + 1))
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (ac > 2)
		set_stack(ac - 1, av + 1, t_stack);
	checker(ac - 1, t_stack);
	return (0);
}
