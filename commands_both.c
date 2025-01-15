/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:49 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/15 05:02:49 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void swap_top_both(int *arr_a,int *arr_b)
{
    swap_top(arr_a);
    swap_top(arr_b);

}

void    rotate_both(int *arr_a,int size_a,int *arr_b,int size_b)
{
    rotate(arr_a,size_a);
    rotate(arr_b,size_b);
}

void    reverse_rotate_both(int *arr_a,int size_a,int *arr_b,int size_b)
{
    reverse_rotate(arr_a,size_a);
    reverse_rotate(arr_b,size_b);
}