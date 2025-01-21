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

static int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	midpoint_finder(int *arr, int size)
{
	int	midpoint;
	int	closest;
	int	i;

	i = 1;
	midpoint = (arr[find_max_pos(arr, size)]
			+ arr[find_min_pos(arr, size)]) / 2;
	closest = arr[0];
	while (i < size)
	{
		if (ft_abs(arr[i] - midpoint) < ft_abs(closest - midpoint))
			closest = arr[i];
		i++;
	}
	return (closest);
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

int	extract_number(const char **str)
{
	long long	number;

	if (!str || !*str)
		return (INT_MIN);
	while (**str && has_spaces(**str))
		(*str)++;
	if (**str == '\0')
		return (INT_MIN);
	if (!is_digit(**str) && **str != '-' && **str != '+')
	{
		write(1, "Error: NAN\n", 12);
		return (INT_MIN);
	}
	number = ft_strtol((char **)str);
	if (!is_valid_int(number))
		return (INT_MIN);
	while (**str && has_spaces(**str))
		(*str)++;
	return ((int)number);
}
