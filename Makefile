# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 17:39:15 by lbaumann          #+#    #+#              #
#    Updated: 2022/12/29 23:27:07 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC = cc
CFLAGS = -Wall -Werror -Wextra -c

BUFFER_SZ = 10

SRCS = get_next_line.c get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SZ) -o $(NAME)

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

