/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:43 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/15 05:02:43 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_top(int *arr)
{
    int    temp;

    if(*arr < 2)
        return ;    
    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
    write(1,"pa\n",3);
}

void    push_top(int *arr_dest, int *size_dest, int *arr_src, int *size_src)
{    
    int     i;

    if (*size_src <= 0 || *size_dest < 0)
        return;
    i = *size_dest;
    while (i > 0)
    {
        arr_dest[i] = arr_dest[i - 1];
        i--;
    }
    arr_dest[0] = arr_src[0];
    (*size_dest)++;
    i = 0;
    while (i < *size_src - 1)
    {
        arr_src[i] = arr_src[i + 1];
        i++;
    }
    (*size_src)--;
   write(1,"pa\n",3);
}

void    rotate(int *arr, int size)
{
    int     new_first;
    int     i;

    if (size <= 1)
        return;
    new_first = arr[0];
    i = 0;
    while (i < size - 1)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    arr[size - 1] = new_first;
    write(1,"pa\n",3);;
}

void    reverse_rotate(int *arr, int size)
{
    int     new_last;
    int     i;

    if (size <= 1)
        return;
    new_last = arr[size - 1];
    i = size - 1;
    while (i > 0)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[0] = new_last;
      write(1,"pa\n",3);
}

void    sort_two_elements(int *arr, int size)
{  
    if (size != 2)
        return ;
    swap_top(arr);
}

