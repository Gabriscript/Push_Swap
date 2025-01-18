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
   // else
     //   write(1,"Warning : found doubles, array resized\n",40);
    return (1); 
}

int *string_to_array(const char *str, int *length) {
    int *array;
    int num;
    int valid_count = 0;

    *length = count_elements(str);
    if (*length == -1) {
        write(1, "Error: NAN\n", 11);
        return NULL;
    }

    array = malloc(*length * sizeof(int));
    if (!array)
        return NULL;

    while (*str) {
        num = extract_number(&str); // Updated to handle spaces correctly
        if (num == INT_MIN) { // Check for errors
            free(array);
            return NULL;
        }

        // Add the number to the array
        if (!process_number(num, array, &valid_count)) {
            free(array);
            return NULL;
        }
    }

    *length = valid_count;
    return array;
}


int extract_number(const char **str) {
    long long number;

    if (!str || !*str)
        return INT_MIN;

    // Skip leading spaces
    while (**str && has_spaces(**str))
        (*str)++;

    if (**str == '\0') // End of string
        return INT_MIN;

    if (!is_digit(**str) && **str != '-' && **str != '+') {
        write(1, "Error: NAN\n", 12);
        return INT_MIN;
    }

    // Extract the number
    number = ft_strtol((char **)str);

    // Check if number is valid
    if (!is_valid_int(number))
        return INT_MIN;

    // Skip trailing spaces or delimiters
    while (**str && has_spaces(**str))
        (*str)++;

    return (int)number;
}






static int *append_sub_array(int *array, int *sub_array, int total_length, int sub_length)
{
    int *new_array = malloc(sizeof(int) * (total_length + sub_length));
    if (!new_array) 
    {
        free(array);
        free(sub_array);
        return NULL;
    }
    if (array)
    {
        memcpy(new_array, array, sizeof(int) * total_length);
        free(array);
    }
    memcpy(new_array + total_length, sub_array, sizeof(int) * sub_length);
    free(sub_array);
    return new_array;
}

int *args_to_array(int ac, const char **av, int *length) 
{
    int i;
    int total_length;
    int sub_length;
    int *sub_array;
    int *array;
    
    array = NULL;
    i = 1;
    total_length = 0;
    while (i < ac) 
    {
        sub_length = 0;
        if (!(sub_array = string_to_array(av[i], &sub_length))) 
        {
            free(array);
            return NULL;
        }
        if (!(array = append_sub_array(array, sub_array, total_length, sub_length)))
            return NULL;
        total_length += sub_length;
        i++;
    }
    *length = total_length;
    return array;
}
/*

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
*/

