/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:08:24 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/20 12:08:24 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	const unsigned char	*src;
	size_t				i;
	unsigned char		*dest;

	i = 0;
	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}

int	seen(int num)
{
	static int	seen[MAX_NUM];
	static int	count;
	int			i;

	i = 0;
	count = 0;
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

int	has_spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
