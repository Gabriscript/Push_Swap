/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:01:33 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/15 05:01:33 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort(int *arr_a, int length)
{
    if(length == 2)
        sort_two_elements(arr_a,length);
    else if(length == 3)
        sort_three_elements(arr_a, length);
    else
        sort_all(arr_a,length);        
        // free(arr_a);
}

int	main(int ac, char **av)
{   
	int     *arr_a;
	int     length;

	if(ac < 2)
		return (1);
	else if(ac == 2)
	{
		arr_a = string_to_array(av[1],&length);
		if (!arr_a)
			return (1);
	}
	else
	{
		arr_a = args_to_array(ac,(const char **) av, &length);
		if (!arr_a)
			return (1);
	}
	if(!is_sorted(arr_a,length))
		sort(arr_a,length);        
}
