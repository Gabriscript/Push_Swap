/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:43 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/22 19:13:16 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(int *arr)
{
	int	temp;

	if (*arr < 2)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void	push_top(int *arr_dst, int *size_dst, int *arr_src, int *size_src)
{
	int	i;

	if (*size_src <= 0 || *size_dst < 0)
		return ;
	i = *size_dst;
	while (i > 0)
	{
		arr_dst[i] = arr_dst[i - 1];
		i--;
	}
	arr_dst[0] = arr_src[0];
	(*size_dst)++;
	i = 0;
	while (i < *size_src - 1)
	{
		arr_src[i] = arr_src[i + 1];
		i++;
	}
	(*size_src)--;
}

void	rotate(int *arr, int size)
{
	int	new_first;
	int	i;

	if (size <= 1)
		return ;
	new_first = arr[0];
	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = new_first;
}

void	reverse_rotate(int *arr, int size)
{
	int	new_last;
	int	i;

	if (size <= 1)
		return ;
	new_last = arr[size - 1];
	i = size - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = new_last;
}
