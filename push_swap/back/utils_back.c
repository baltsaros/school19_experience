#include "push_swap.c"

// void	check_sort(int *array, int length)
// {
// 	int	i;
// 	int	j;
// 	int	check;

// 	i = 0;
// 	check = 1;
// 	while (i < length)
// 	{
// 		j = i + 1;
// 		while (j < length)
// 		{
// 			if (array[i] > array[j])
// 				check = 0;
// 			++j;
// 		}
// 		++i;
// 	}
// 	if (check)
// 	{
// 		write(1, "OK\n", 3);
// 		exit(EXIT_SUCCESS);
// 	}
// }

// void	check_error(int error, int *array)
// {
// 	if (error)
// 	{
// 		free(array);
// 		error_msg();
// 	}
// }

// void	ft_sort_big_b(t_data *data)
// {
// 	int	limit;

// 	data->med = ft_find_med_chunk(data->b, data->b->flag);
// 	if (ft_chunk_len(data->b, data->b->flag) == 1)
// 	{
// 		pa(data);
		
// 	}
// 	if (data->b->ix < data->med && data->b->next->ix < data->med)
// 	{
// 		rb(data);
// 		++data->rb;
// 	}
// 	if (data->b->next->ix > data->med && data->b->next->ix > data->b->ix)
// 		sb(data);
// 	if (data->b->ix > data->med)
// 		pa(data);
// 	if (data->b->prev->ix > data->b->ix && data->rb)
// 	{
// 		rrb(data);
// 		--data->rb;
// 	}
// 	if (data->len_b > 3)
// 	{
// 		ft_sort_big_b(data);
// 		return ;
// 	}
// 	ft_sort_three_b(data);
// }