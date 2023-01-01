# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 17:39:15 by lbaumann          #+#    #+#              #
#    Updated: 2023/01/01 19:38:15 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC = cc
CFLAGS = -Wall -Werror -Wextra -c -D BUFFER_SIZE=$(BUFFER_SZ)
CFLAGS_2 = -Wall -Werror -Wextra

BUFFER_SZ = 10

SRCS = get_next_line.c get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS_2) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	@cc -D BUFFER_SIZE=$(BUFFER_SZ) $(SRCS)
	@./a.out

debug:
	@cc -g -D BUFFER_SIZE=$(BUFFER_SZ) $(SRCS)

.PHONY: all clean fclean re test

