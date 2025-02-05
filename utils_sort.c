/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:31 by ggargani          #+#    #+#             */
/*   Updated: 2025/01/31 11:59:29 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*static int is_in_chunk(int current, int *pivots, int chunk, int num_chunks)
{
    if (num_chunks <= 0 || chunk < 0 || chunk >= num_chunks)
        return 0;  // Gestione errore

    if (num_chunks == 1)
        return 1;  // Se c'è solo un chunk, tutto è in quel chunk

    if (chunk == 0 && current <= pivots[0])
        return 1;
    else if (chunk == num_chunks - 1 && current > pivots[num_chunks - 2])
        return 1;
    else if (chunk > 0 && chunk < num_chunks - 1 && 
             current > pivots[chunk - 1] && current <= pivots[chunk])
        return 1;
-fsanitize=address -fsanitize=leak -fsanitize=undefined -ggdb3
    return 0;
}*/
static int	is_in_chunk(int current, int *pivots, int chunk, int num_chunks)
{
	if (current <= pivots[0])
		return (1);
	else if (current > pivots[num_chunks - 2])
		return (1);
	else if (current > pivots[chunk - 1] && current <= pivots[chunk])
		return (1);
	return (0);
}

static void	process_element(t_stack_data *data, int in_chunk)
{
	if (in_chunk)
	{
		push_top(data->arr_b, &data->size_b, data->arr_a, &data->size_a);
		print_command("pb");
		if (data->size_b > 1 && data->arr_b[0] < data->arr_b[1]
			&& data->arr_b[1] < data->arr_b[0])
			swap_top_both(data->arr_b, data->arr_b);
	}
	else
	{
		rotate(data->arr_a, data->size_a);
		print_command("ra");
	}
}

static void	chunker(t_stack_data *data, int *pivots, int chunk, int num_chunks)
{
	int	original_size_a;
	int	current;
	int	in_chunk;

	original_size_a = data->size_a;
	while (original_size_a > 0)
	{
		current = data->arr_a[0];
		in_chunk = is_in_chunk(current, pivots, chunk, num_chunks);
		process_element(data, in_chunk);
		original_size_a--;
	}
}

static void	init_arrays(t_stack_data *data, int **pivots, int **temp_arr)
{
	int	i;
	int	num_chunks;

	i = 0;
	num_chunks = get_num_chunks(data->size_a);
	*pivots = malloc(sizeof(int) * (num_chunks - 1));
	if (!(*pivots))
		exit(1);
	*temp_arr = malloc(sizeof(int) * data->size_a);
	if (!(*temp_arr))
	{
		free(*pivots);
		*pivots = NULL;
		exit(1);
	}
	while (i < data->size_a)
	{
		(*temp_arr)[i] = data->arr_a[i];
		i++;
	}
}

void	divide_array(t_stack_data *data)
{
	int	num_chunks;
	int	*pivots;
	int	*temp_arr;
	int	chunk;

	num_chunks = get_num_chunks(data->size_a);
	init_arrays(data, &pivots, &temp_arr);
	count_pivots(temp_arr, data->size_a, pivots, num_chunks);
	free(temp_arr);
	chunk = 0;
	while (chunk < num_chunks)
	{
		chunker(data, pivots, chunk, num_chunks);
		chunk++;
	}
	free(pivots);
}
