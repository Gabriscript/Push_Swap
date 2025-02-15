/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:03:28 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/22 19:07:37 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef MAX_NUM
#  define MAX_NUM 2000
# endif

typedef struct s_stack_data
{
	int		*arr_a;
	int		*arr_b;
	int		size_a;
	int		size_b;
	int		length;
}	t_stack_data;
long long	extract_number(const char **str);
long long	ft_strtol(char **str);
int			is_sorted(int *arr, int size);
int			get_num_chunks(int size);
int			count_elements(const char *str);
int			is_valid_int(long long num);
int			has_only_number(char *str);
int			is_digit(int num);
int			has_spaces(char c);
int			seen(int num);
int			*string_to_array(const char *str, int *length);
int			*args_to_array(int ac, const char **av, int *length);
int			find_min_pos(int *arr, int size);
int			find_max_pos(int *arr, int size);
void		print_command(char *cmd);
void		swap_top(int *arr);
void		sort(int *array, int length);
void		reverse_rotate(int *arr, int size);
void		rotate(int *arr, int size);
void		push_top(int *arr_dst, int *size_dst, int *arr_src, int *size_src);
void		reverse_rotate_both(int *arr_a, int size_a, int *arr_b, int size_b);
void		rotate_both(int *arr_a, int size_a, int *arr_b, int size_b);
void		swap_top_both(int *arr_a, int *arr_b);
void		bring_min_to_top(int *arr, int size);
void		bring_max_to_top(int *arr, int size);
void		*ft_memcpy(void *destination, const void *source, size_t num);
void		send_back(t_stack_data *data);
void		divide_array(t_stack_data *data);
void		count_pivots(int *temp_arr, int size, int *pivots, int num_chunks);

#endif