/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:01:33 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/22 19:07:33 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(arr);
	return (0);
}
