/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:35 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/22 19:19:25 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(int *arr, int size)
{
	int	max;

	if (size != 3)
		return ;
	max = find_max_pos(arr, size);
	if (max != 2)
	{
		if (max == 0)
		{
			rotate(arr, size);
			//write(1, "ra\n", 4);
		}
		else if (max == 1)
		{
			reverse_rotate(arr, size);
			//write(1, "rra\n", 5);
		}
	}
	if (arr[0] > arr[1])
		swap_top(arr);
}

static void	divide_array(t_stack_data *data, int pivot)
{
	int	original_size_a;
	int	i;

	i = 0;
	original_size_a = data->size_a;
	while (i < original_size_a)
	{
		if (data->arr_a[0] <= pivot)
		{
			push_top(data->arr_b, &data->size_b, data->arr_a, &data->size_a);
			//write(1, "pb\n", 4);
			//printf("pb\n");
		}
		else
		{
			reverse_rotate(data->arr_a, data->size_a);
			//write(1, "rra\n", 5);
			//printf("rra\n");
		}
		i++;
	}
}

static void	handle_reverse_sorted(int *arr_a, int *size_a)
{
	while (*size_a > 1)
	{
		rotate(arr_a, *size_a);
		//write(1, "ra\n", 4);
		(*size_a)--;
	}
}

void	send_back(t_stack_data *data)
{
	while (data->size_b > 0)
	{
		bring_max_to_top(data->arr_b, data->size_b);
		push_top(data->arr_a, &data->size_a, data->arr_b, &data->size_b);
		//write(1, "pa\n", 4);
		if (data->size_a > 1 && data->arr_a[0] > data->arr_a[1])
			swap_top(data->arr_a);
	}
}

void	sort_all(int *arr_a, int length)
{
	int				pivot;
	t_stack_data	data;

	data.arr_a = arr_a;
	data.size_a = length;
	data.size_b = 0;
	data.length = length;
	if (is_sorted(data.arr_a, length) || length <= 1)
		return ;
	if (is_reverse_sorted(data.arr_a, length))
	{
		handle_reverse_sorted(data.arr_a, &data.size_a);
		return ;
	}
	data.arr_b = malloc(length * sizeof(int));
	if (!data.arr_b)
		return ;
	pivot = midpoint_finder(data.arr_a, length);
	divide_array(&data, pivot);
	sort_all(data.arr_a, data.size_a);
	send_back(&data);
	free(data.arr_b);
}
