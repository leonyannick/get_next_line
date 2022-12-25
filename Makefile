# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 17:39:15 by lbaumann          #+#    #+#              #
#    Updated: 2022/12/25 00:30:15 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 11:21:05 by lbaumann          #+#    #+#              #
#    Updated: 2022/12/21 21:18:44 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC = cc
CFLAGS = -Wall -Werror -Wextra

BUFFER_SZ = 15

SRCS = get_next_line.c get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SZ) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	@cc -D BUFFER_SIZE=$(BUFFER_SZ) $(SRCS)
	@./a.out

.PHONY: all clean fclean re test

