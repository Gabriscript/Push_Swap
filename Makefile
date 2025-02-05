# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 09:16:06 by ggargani          #+#    #+#              #
#    Updated: 2025/01/31 10:55:26 by ggargani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror  // -fsanitize=address -fsanitize=leak -fsanitize=undefined -ggdb3

SRCS = main.c utils_one.c utils_two.c sort.c string_handler.c \
	   commands.c commands_both.c checker_functions.c checker_functions_two.c \
	   utils_sort.c utils_sort_two.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
