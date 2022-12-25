/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:24 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/25 13:11:53 by lbaumann         ###   ########.fr       */
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
-read fails if nbyte exceeds INT_MAX
-read Return values: number of bytes read, end of file: 0, in case of error: -1
*/
char	*get_next_line(int fd)
{
	char		*buffer;
	size_t		buffer_size;
	static int	i;
	ssize_t		read_ret;

	if (fd == -1)
		return (NULL);
	buffer_size = BUFFER_SIZE;
	buffer = calloc(sizeof(char), buffer_size);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer_size)
	{
		read_ret = read(fd, &buffer[i], 1);
		if (read_ret == -1 || read_ret == 0)
			return (NULL);
		if (buffer[i] == '\n')
			break;
		i++;
		buffer_size--;
	}
	return (buffer);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);

	// printf("[%i]", fd);
	char	*res;

	res = get_next_line(fd);
	printf("%s", res);
	printf("\n%p", res);
	res = get_next_line(fd);
	printf("%s", res);
	printf("\n%p", res);
	
	// while((res = get_next_line(fd)))
	// 	printf("%s", res);
	
	


	//system("leaks a.out");
}
