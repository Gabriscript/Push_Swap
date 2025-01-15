/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:06 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/15 05:02:06 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int     count_elements(const char *str)
{
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (has_spaces(str[i]))
            i++;
        if (!str[i])
            break;
        if (str[i] == '+' || str[i] == '-')
            i++;
        while (is_digit(str[i]))
            i++;
        count++;
    }
    return (count);
}



long long   ft_strtol(char **str)
{
    long    i;
    long    result;
    int     sign;

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
        return(INT_MIN);
    return(result);
}

void    bring_min_to_top(int *arr, int size)
{
    int     min_index;
    
    min_index = find_min_pos(arr, size);
    if (min_index < size / 2)
    {
        while (min_index > 0)
        {
            rotate(arr, size);
            min_index--;
        }
    }else
    {
         while (min_index < size)
        {
            reverse_rotate(arr, size);
            min_index++;
        }
    }
}

int     seen(int num)
{
    static int      seen[MAX_NUM];
    static int      count;
    int     i;

    count = 0;
    i = 0;
    while (i < count)
    {
        if (seen[i] == num)
            return (1);
        i++;
    }
    if (count >= MAX_NUM)
        return (1); 
    seen[count] = num;
    count++;
    return (0);
}

void    bring_max_to_top(int *arr, int size)
{
    int max_index;
    
    max_index = find_max_pos(arr, size);    
    if (max_index < size / 2) 
    {
        while (max_index > 0)
        {
            rotate(arr, size);         
            max_index--;
        }
    } 
    else
    {
        while (max_index < size)
        {
            reverse_rotate(arr, size);             
            max_index++;
        }
    }
}


