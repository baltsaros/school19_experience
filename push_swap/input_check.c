#include "push_swap.h"

void	error_msg()
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

int		*ft_array_dup(int *old, int *new, int length)
{
	int	i;

	if (!old)
		return (0);
	i = 0;
	while (i < length)
	{
		new[i] = old[i];
		++i;
	}
	return (new);
}

void	check_duplicate(int *array, int length)
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
			error_msg();
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

int		*ft_sort_array(int *array, int length)
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

void	input_check(int argc, char *argv[])
{
	int		i;
	int		len;
	int		*ar;
	int		*ar_s;
	t_node	*stack_a;
	t_node	*stack_b;

	ar = malloc(sizeof(int) * (argc - 1));
	alloc_check_small(ar);
	i = 1;
	len = 0;
	while (argv[i])
	{
		ar[len] = ft_atoi(argv[i]);
		// printf("ar[%d] is %d, argv[%d] is %s\n", len, ar[len], i, argv[i]);
		++i;
		++len;
	}
	check_duplicate(ar, len);
	check_sort(ar, len);
	ar_s = ft_sort_array(ar, len);
	i = 0;
	while (i < len)
	{
		printf("ar[%d] is %d, ar_s[%d] is %d\n", i, ar[i], i, ar_s[i]);
		++i;
	}
	stack_a = ft_init_stack(ar, ar_s, len);
	ft_node_print(stack_a);
	ft_push(&stack_a, &stack_b);
	printf("after\n");
	ft_node_print(stack_a);
	printf("stack_b\n");
	ft_node_print(stack_b);

}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	input_check(argc, argv);
	return (0);
}
