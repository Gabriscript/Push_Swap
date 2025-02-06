/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:20 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/15 05:02:20 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_strtol(char **str)
{
	long long	result;
	long		i;
	int			sign;

	if (!str || !*str)
		return (0);
	sign = 1;
	result = 0;
	i = 0;
	if ((*str)[i] == '+' || (*str)[i] == '-')
	{
		if ((*str)[i] == '-')
			sign = -1;
		i++;
	}
	while (is_digit((*str)[i]))
	{
		result = result * 10 + ((*str)[i] - '0');
		i++;
	}
	*str += i;
	result *= sign;
	if (!is_valid_int(result))
		return (INT_MIN);
	return (result);
}

int	find_min_pos(int *arr, int size)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < size)
	{
		if (arr[i] < arr[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	find_max_pos(int *arr, int size)
{
	int	max_index;
	int	i;

	if (size <= 0)
		return (-1);
	max_index = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > arr[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

void	bring_min_to_top(int *arr, int size)
{
	int	min_index;

	min_index = find_min_pos(arr, size);
	if (min_index < size / 2)
	{
		while (min_index > 0)
		{
			rotate(arr, size);
			print_command("ra");
			min_index--;
		}
	}
	else
	{
		while (min_index < size)
		{
			reverse_rotate(arr, size);
			print_command("rra");
			min_index++;
		}
	}
}

void	bring_max_to_top(int *arr, int size)
{
	int	max_index;

	max_index = find_max_pos(arr, size);
	if (max_index < size / 2)
	{
		while (max_index > 0)
		{
			rotate(arr, size);
			print_command("rb");
			max_index--;
		}
	}
	else
	{
		while (max_index < size)
		{
			reverse_rotate(arr, size);
			print_command("rrb");
			max_index++;
		}
	}
}
