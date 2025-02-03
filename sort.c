/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:35 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/03 08:31:26 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_elements(int *arr)
{
	swap_top(arr);
	print_command("sa");
}

static void	sort_three_elements(int *arr)
{
	int	max;

	max = find_max_pos(arr, 3);
	if (max != 2)
	{
		if (max == 0)
		{
			rotate(arr, 3);
			print_command("ra");
		}
		else if (max == 1)
		{
			reverse_rotate(arr, 3);
			print_command("rra");
		}
	}
	if (arr[0] > arr[1])
	{
		swap_top(arr);
		print_command("sa");
	}
}

static void	sort_few_elements(int *arr, int size)
{
	int	size_b;
	int	*arr_b;

	size_b = 0;
	arr_b = malloc(size * sizeof(int));
	if (!arr_b)
		return ;
	while (size > 3)
	{
		bring_min_to_top(arr, size);
		push_top(arr_b, &size_b, arr, &size);
		print_command("pb");
		size--;
	}
	sort_three_elements(arr);
	while (size_b > 0)
	{
		push_top(arr, &size, arr_b, &size_b);
		print_command("pa");
		size_b--;
	}
	free(arr_b);
}

static void	sort_all(int *arr_a, int length)
{
	t_stack_data	data;

	data.arr_a = arr_a;
	data.size_a = length;
	data.size_b = 0;
	data.arr_b = malloc(length * sizeof(int));
	if (!data.arr_b)
		return ;
	divide_array(&data);
	send_back(&data);
	free(data.arr_b);
}

void	sort(int *array, int length)
{
	if (length == 2)
		sort_two_elements(array);
	else if (length == 3)
		sort_three_elements(array);
	else if (length == 5 || length == 4)
		sort_few_elements(array, length);
	else
		sort_all(array, length);
}
