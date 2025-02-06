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

static int	check_number_length(const char *str)
{
	int	digit_count;

	digit_count = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && is_digit(*str))
	{
		digit_count++;
		str++;
	}
	if (digit_count <= 11)
		return (1);
	return (0);
}

long long	extract_number(const char **str)
{
	long long	number;

	if (!str || !*str)
		return (INT_MIN);
	while (**str && has_spaces(**str))
		(*str)++;
	if (**str == '\0')
		return (INT_MIN);
	if (!is_digit(**str) && **str != '-' && **str != '+')
		return (INT_MIN);
	if (!check_number_length(*str))
		return (INT_MIN);
	number = ft_strtol((char **)str);
	if (!is_valid_int(number))
		return (INT_MIN);
	while (**str && has_spaces(**str))
		(*str)++;
	return (number);
}
