/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:35 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/15 05:02:35 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    sort_three_elements(int *arr, int size)
{
    int     max;

    if (size != 3)		 
        return ;
		
    max = find_max_pos(arr,size);
    if (max != 2)
    {
        if(max == 0){
            rotate(arr,size);
			// write(1,"ra\n",4);
		}
        else if(max == 1){
            reverse_rotate(arr,size);
			// write(1,"rra\n",5);
		}
    }
   if (arr[0] > arr[1])
   {
          swap_top(arr);
		// write(1,"sa\n",4);
	}

}

void divide_array(int *arr_a, int *arr_b, int *size_a, int *size_b, int pivot)
{
    int original_size_a;
	int i;

	 i = 0;
	 original_size_a = *size_a;
    while (i < original_size_a)
	{
        if (arr_a[0] <= pivot)
            {
				push_top(arr_b, size_b, arr_a, size_a); // Push smaller or equal values to arr_b
				//write(1,"pb\n",4);
			}
        else{
            rotate(arr_a, *size_a); // Rotate larger values to the back of arr_a
			// write(1,"ra\n",4);
			 }
		i++;
    }
}

static void	handle_reverse_sorted(int *arr_a, int *size_a)
{
	while (*size_a > 0)
	{
		bring_max_to_top(arr_a, *size_a);
		rotate(arr_a, *size_a);
		 //write(1,"ra\n",4);
		(*size_a)--;
	}
}

void	sort_all(int *arr_a, int length)
{
	int	size_a;
	int	size_b;
	int	*arr_b;
	int	pivot;

	size_a = length;
	size_b = 0;
	if (is_sorted(arr_a, length) || length <= 1)
		return ;
	if (is_reverse_sorted(arr_a, length))
	{
		handle_reverse_sorted(arr_a, &size_a);
		return ;
	}
	arr_b = malloc(length * sizeof(int));
	if (!arr_b)
		return ;
	pivot = midpoint_finder(arr_a, length);
	divide_array(arr_a, arr_b, &size_a, &size_b, pivot);	
	sort_all(arr_a, size_a);
	while (size_b > 0)
	{
		bring_max_to_top(arr_b, size_b);
		push_top(arr_a, &size_a, arr_b, &size_b);
		// write(1,"pa\n",4);
	}
	free(arr_b);
}