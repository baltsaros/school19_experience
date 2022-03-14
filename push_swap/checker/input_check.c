#include "push_swap.h"

void	check_duplicate(int *array, int length, int *error)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length && array[i] != array[j])
			++j;
		if (array[i] == array[j])
			*error = 1;
		++i;
	}
}

void	check_sort(int *array, int length)
{
	int	i;

	i = 0;
	while (i + 1 < length && array[i] < array[i + 1])
		++i;
	if (i + 1 == length)
	{
		write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
}

int	*ft_sort_array(int *array, int length)
{
	int	*ar_s;
	int	i;
	int	j;

	i = 0;
	ar_s = malloc(sizeof(int) * length);
	alloc_check_small(ar_s);
	ar_s = ft_array_dup(array, ar_s, length);
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (ar_s[i] > ar_s[j])
				ft_swap(&ar_s[i], &ar_s[j]);
			++j;
		}
		++i;
	}
	return (ar_s);
}

t_node	*ft_init_stack(int *ar, int *ar_s, int length)
{
	t_node	*stack;
	t_node	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (ar_s[j] != ar[i])
			++j;
		if (ar_s[j] == ar[i])
		{
			if (i == 0)
			{
				stack = ft_node_new(j + 1, ar[i]);
				alloc_check_small(stack);
			}
			else
			{
				tmp = ft_node_new(j + 1, ar[i]);
				alloc_check_node(tmp, &stack);
				ft_node_back(&stack, tmp);
			}
		}
		++i;
	}
	return (stack);
}

t_node	*input_check(int argc, char *argv[])
{
	int		error;
	int		len;
	int		*ar;
	int		*ar_s;
	t_node	*stack_a;

	ar = malloc(sizeof(int) * (argc - 1));
	alloc_check_small(ar);
	len = 0;
	error = 0;
	while (argv[len + 1])
	{
		ar[len] = ft_atoi(argv[len + 1], &error);
		++len;
	}
	check_duplicate(ar, len, &error);
	if (error)
	{
		free(ar);
		error_msg();
	}
	check_sort(ar, len);
	ar_s = ft_sort_array(ar, len);
	stack_a = ft_init_stack(ar, ar_s, len);
	return (stack_a);
}
