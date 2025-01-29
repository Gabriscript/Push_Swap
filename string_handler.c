/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:01:50 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/22 16:49:27 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_number(int num, int *array, int *valid_count)
{
	if (num == INT_MIN)
		return (0);
	if (seen(num))
		return (0);
	array[*valid_count] = num;
	(*valid_count)++;
	return (1);
}

static int	tiny_check(long long num, int *array, int *count)
{
	if (num == INT_MIN)
	{
		free(array);
		write(2, "Error\n", 6);
		return (0);
	}
	if (!process_number(num, array, count))
	{
		write(2, "Error\n", 6);
		free(array);
		return (0);
	}
	return (1);
}

int	*string_to_array(const char *str, int *length)
{
	long long	num;
	int			valid_count;
	int			*array;

	*length = count_elements(str);
	valid_count = 0;
	if (*length == -1)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	array = malloc(*length * sizeof(int));
	if (!array)
		return (NULL);
	while (*str)
	{
		num = extract_number(&str);
		if (!tiny_check(num, array, &valid_count))
			return (NULL);
	}
	*length = valid_count;
	return (array);
}

static int	*append_sub_array(int *arr, int *sub_arr, int tot_len, int sub_len)
{
	int	*new_array;

	new_array = malloc(sizeof(int) * (tot_len + sub_len));
	if (!new_array)
	{
		free(arr);
		return (NULL);
	}
	if (arr)
	{
		ft_memcpy(new_array, arr, sizeof(int) * tot_len);
		free(arr);
	}
	ft_memcpy(new_array + tot_len, sub_arr, sizeof(int) * sub_len);
	return (new_array);
}

int	*args_to_array(int ac, const char **av, int *length)
{
	t_stack_data	data;

	data.arr_a = NULL;
	data.length = 1;
	data.size_a = 0;
	while (data.length < ac)
	{
		data.size_b = 0;
		data.arr_b = string_to_array(av[data.length], &data.size_b);
		if (!data.arr_b)
		{
			free(data.arr_a);
			return (NULL);
		}
		data.arr_a = append_sub_array
			(data.arr_a, data.arr_b, data.size_a, data.size_b);
		free(data.arr_b);
		if (!data.arr_a)
			return (NULL);
		data.size_a += data.size_b;
		data.length++;
	}
	*length = data.size_a;
	return (data.arr_a);
}
