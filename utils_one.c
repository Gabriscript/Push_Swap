/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:06 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/22 19:12:50 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elements(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (has_spaces(str[i]))
			i++;
		if (!str[i])
			return (-1);
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

long long	ft_strtol(char **str)
{
	long long	result;
	long		i;
	int			sign;

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
		return (INT_MIN);
	return (result);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	print_command(char *cmd)
{
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
}
