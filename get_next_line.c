/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:24 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/29 23:59:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*
-BUFFER_SIZE macro is safed in buffer_size variable so it can be modified
-newline is included in buffer (except if BUFFER_SIZE is less than line length)
-calloc is used for buffer allocation, in case allocated memory would have
prev value in it -> would return in messed up output
-return value from read is saved in static variable read_ret, so that
buffer can be returned when EOF is encountered in line with text and
the next get_next_line call can return NULL
*/
char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	buffer_size;
	int		i;
	static ssize_t	read_ret = 1;

	if (fd < 0)
		return (NULL);
	if (read_ret == 0)
		return (NULL);
	buffer_size = BUFFER_SIZE;
	buffer = ft_calloc(buffer_size, sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer_size)
	{
		read_ret = read(fd, &buffer[i], 1);
		if (read_ret == -1)
			return (NULL);
		if (buffer[i] == '\n' || read_ret == 0)
			break;
		i++;
		buffer_size--;
	}
	return(buffer);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char	*res;

	res = get_next_line(fd);
	printf("%s", res);
	res = get_next_line(fd);
	printf("%s", res);
	// res = get_next_line(1);
	// printf("%s", res);
}
