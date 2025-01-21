/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:28 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/15 05:02:28 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(long long num)
{
	if (num >= INT_MIN && num <= INT_MAX)
		return (1);
	else
		write(1, "Error : number too large\n", 26);
	return (0);
}

int	has_only_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!is_digit(str[i]))
			return (0);
		while (is_digit(str[i]))
			i++;
		if (str[i] && str[i] != ' ')
			return (0);
	}
	return (1);
}

int	is_digit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	return (0);
}

int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_reverse_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
