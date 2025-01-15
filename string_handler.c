/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:01:50 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/15 05:01:50 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int process_number(int num, int *array, int *valid_count)
 {
    if (num == INT_MIN)
        return (0); 
    if (!seen(num))
    {
        array[*valid_count] = num;
        (*valid_count)++;
    }
    return (1); 
}

int     *string_to_array(const char *str, int *length)
{
    int *array;
    int num;
    int valid_count;

    valid_count = 0;
    *length = count_elements(str);
    if (*length == -1)
    {
        write(1,"Error : invalid input\n",23);
        return (NULL);
    }
    array = malloc(*length * sizeof(int));
    if (!array)
     return (NULL);
    while (*str) {
        num = extract_number(&str);
       if (!process_number(num, array, &valid_count))
        {
            free(array);
            return (NULL);
        }
    }
    *length = valid_count;
    return (array);
}


int     extract_number(const char **str)
{
    long long   number;

    if (!str || !*str)
        return (INT_MIN);    
    while (**str && has_spaces(**str))
        (*str)++;
    if ((**str == '\0') || (!is_digit(**str) && **str != '-' && **str != '+'))
    {
            write(1,"Error : invalid input\n",23);
            return (INT_MIN);
    }      
    number = ft_strtol((char **)str);
    if (!is_valid_int(number))
        return (INT_MIN);
    return ((int)number);
}


int     *args_to_array(int ac, const char **av, int *length)
{
    int i;
    int num;
    int valid_count ;
    int *array;    
    
    valid_count = 0;    
    *length = ac - 1;
    array = malloc(sizeof(int) * *length);
    if (!array) 
        return (NULL);    
    i = 0;
    while (i < *length)
    {   
        num = extract_number(&av[i + 1]);
        if (!process_number(num, array, &valid_count))
        {
            free(array);
            return (NULL);
        }
        i++;
    }
    *length = valid_count;
     return (array);
}


