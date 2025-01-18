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
         if ((str[i] == '+' || str[i] == '-') && is_digit(str[i + 1]))
            i++;
        else if (!is_digit(str[i]))
            return (-1);
        while (is_digit(str[i]))
            i++;
        count++;
        if (!has_spaces(str[i]) && str[i] != '\0')
            return (-1);
    }
    return (count);
}

long long   ft_strtol(char **str)
{
    long    i;
    long long   result;
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
             write(1,"ra\n",3);
            min_index--;
        }
    }else
    {
         while (min_index < size)
        {
            reverse_rotate(arr, size);
             write(1,"rra\n",4);
            min_index++;
        }
    }
}

int seen(int num)
{
    static int seen[MAX_NUM];
    static int count = 0;
    int i;

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
             write(1,"rb\n",4);         
            max_index--;
        }
    } 
    else
    {
        while (max_index < size)
        {
            reverse_rotate(arr, size);   
             write(1,"rrb\n",4);          
            max_index++;
        }
    }
}


