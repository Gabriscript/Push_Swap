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
        if(max == 0)
            rotate(arr,size);
        else if(max == 1)
            reverse_rotate(arr,size);
    }
    if (arr[0] > arr[1])
                swap_top(arr);
}

static void reverse_sorting(int *arr_dest, int *size_dest, int *arr_src, int *size_src) {
    while (*size_src > 0) {
        bring_max_to_top(arr_src, *size_src);
        push_top(arr_dest, size_dest, arr_src, size_src); // Push to B
    }
    while (*size_dest > 0) {
        push_top(arr_src, size_src, arr_dest, size_dest); // Return to A
    }
    return; // Memory management responsibility remains with the caller
}

static int initial_checks(int *arr_a, int length)
{
    if (is_sorted(arr_a, length) || length <= 1)
        return 1;
    if (is_reverse_sorted(arr_a, length))
    {
        reverse_sorting(arr_a, &length, NULL, 0);
        return 1;
    }
    return 0;
}

static void divide_array(int *arr_a, int *arr_b, int *size_a, int *size_b, int pivot)
{
    int i = 0;
    while (i < *size_a)
    {
        if (arr_a[0] <= pivot)
            push_top(arr_b, size_b, arr_a, size_a);
        else 
            rotate(arr_a, *size_a);
        i++;
    }
}

void    sort_all(int *arr_a, int length) 
{
    int size_a;
    int size_b;
    int *arr_b;
    int pivot;
    
    size_a = length;
    size_b = 0;    
    if (initial_checks(arr_a, length))
        return;
    arr_b = malloc(length * sizeof(int));
    if (!arr_b)
         return;      
    pivot = midpoint_finder(arr_a, length);
    divide_array(arr_a, arr_b, &size_a, &size_b, pivot);
    sort_all(arr_a, size_a);
    while (size_b > 0)
    {
        bring_max_to_top(arr_b, size_b); 
        push_top(arr_a, &size_a, arr_b, &size_b); 
    }
    free(arr_b); 
}