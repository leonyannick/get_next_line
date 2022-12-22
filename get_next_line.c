/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:24 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/22 19:48:53 by lbaumann         ###   ########.fr       */
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

*/
char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	buffer_size;
	int		i;

	if (fd == -1)
		return (NULL);
	buffer_size = BUFFER_SIZE;
	buffer = calloc(sizeof(char), buffer_size);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	printf("%li\n", buffer_size);
	while (buffer_size)
	{
		// printf("loop\n");
		read(fd, &buffer[i], 1);
		if (buffer[i] == '\n')
			break;
		i++;
		buffer_size--;
	}
	
	


	printf("%s", buffer);
	
	
	
	return(0);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);

	// printf("[%i]", fd);
	
	get_next_line(fd);
}
