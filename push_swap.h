#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdlib.h>
# include<limits.h>
#include<unistd.h>

#ifndef MAX_NUM
# define MAX_NUM 500
#endif

void    swap_top(int *arr);
int     is_sorted(int *arr,int size);
void    sort_three_elements(int *arr, int size);
void    sort_two_elements(int *arr, int size);
void    sort_all(int *arr_a, int length);
void    reverse_rotate(int *arr,int size);
void    rotate(int *arr,int size);
void    push_top(int *arr_dest, int *size_dest, int *arr_src, int *size_src);
void    reverse_rotate_both(int *arr_a,int size_a,int *arr_b,int size_b);
void    rotate_both(int *arr_a,int size_a,int *arr_b,int size_b);
void    swap_top_both(int *arr_a,int *arr_b);
int     count_elements(const char *str);
int     is_valid_int(long num);
int     has_only_number(char *str);
int     is_digit(int num);
long long   ft_strtol(char **str);
int     has_spaces(char c);
int     *string_to_array(const char *str,int *length);
int     *args_to_array(int ac, const char **av, int *length);
int     extract_number(const char **str);
void     bring_min_to_top(int *arr, int size);
void    bring_max_to_top(int *arr, int size);
int     seen(int num);
int     midpoint_finder(int *arr,int size);
int find_min_pos(int *arr, int size);
int     find_max_pos(int *arr, int size);
void    sort(int *arr_a, int length);
int     is_reverse_sorted(int *arr, int size);

#endif