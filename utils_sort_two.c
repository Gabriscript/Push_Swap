/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:08:24 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/29 15:08:24 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	count_pivots(int *temp_arr, int size, int *pivots, int num_chunks)
{
	int	i;

	bubble_sort(temp_arr, size);
	i = 1;
	while (i < num_chunks)
	{
		pivots[i - 1] = temp_arr[(size * i) / num_chunks];
		i++;
	}
}

int	get_num_chunks(int size)
{
	if (size >= 500)
		return (11);
	if (size >= 300)
		return (8);
	if (size >= 200)
		return (6);
	if (size >= 100)
		return (4);
	return (2);
}

void	send_back(t_stack_data *data)
{
	while (data->size_b > 0)
	{
		bring_max_to_top(data->arr_b, data->size_b);
		push_top(data->arr_a, &data->size_a, data->arr_b, &data->size_b);
		print_command("pa");
	}
}
