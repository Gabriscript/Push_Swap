/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:01:33 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/22 19:07:33 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(int *av, int length)
{
	if (length == 2)
		sort_two_elements(av, length);
	else if (length == 3)
		sort_three_elements(av, length);
	else
		sort_all(av, length);
}
	
int	main(int ac, char **av)
{
	int	*arr;
	int	length;

	if (ac < 2)
		return (1);
	if (ac == 2)
	{
		arr = string_to_array(av[1], &length);
		if (!arr)
			return (1);
	}
	else
	{
		arr = args_to_array(ac, (const char **)av, &length);
		if (!arr)
			return (1);
	}
	if (!is_sorted(arr, length))
		sort(arr, length);
	//for (int i = 0;i < length;i++)
	//printf("%d ",arr[i]);
	free(arr);
	return (0);
}
