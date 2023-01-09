/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:24 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/09 10:00:40 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static void	*gnl_free(char *mem)
{
	free (mem);
	return (NULL);
}

static char	*gnl_save(char **stash)
{
	char	*line;
	char	*temp;
	size_t	line_len;
	size_t	stash_len_remain;

	stash_len_remain = ft_strlen(ft_strchr(*stash, '\n')) - 1;
	line_len = ft_strlen(*stash) - ft_strlen(ft_strchr(*stash, '\n')) + 1;
	
	line = ft_substr(*stash, 0, line_len);
	temp = *stash;
	*stash = ft_substr(*stash, line_len, stash_len_remain);
	free(temp);
	/* i = 0;
	line = malloc((line_len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	stash_remain = malloc((stash_len_remain + 1) * sizeof(char));
	if (stash_remain == NULL)
		return (NULL);
	while ((*stash)[i] != '\n' && (*stash)[i])
	{
		line[i] = (*stash)[i];
		i++;
	}
	if ((*stash)[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	stash_remain = ft_strjoin(stash_remain, &(*stash)[i]);
	free(*stash);
	*stash = ft_strjoin(*stash, stash_remain);
	free(stash_remain); */
	return (line);
}

static char	*gnl_parse(int fd, char **stash, char *buffer)
{
	ssize_t	read_ret;
	char	*temp;

	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret == 0)
	{
		free(*stash);
		return (gnl_free(buffer));
	}
	if (!*stash)
		*stash = ft_substr(buffer, 0, BUFFER_SIZE);
	else
	{
		temp = *stash;
		*stash = ft_strjoin(*stash, buffer);
		free(temp);
	}
	while (!ft_strchr(buffer, '\n') && read_ret == BUFFER_SIZE)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		read_ret = read(fd, buffer, BUFFER_SIZE);
		temp = *stash;
		*stash = ft_strjoin(*stash, buffer);
		free(temp);
	}
	free(buffer);
	return (gnl_save(stash));
}

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
	char		*buffer;
	static char	*stash;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (gnl_free(buffer));
	
	return (gnl_parse(fd, &stash, buffer));
}

void	test2(char *test)
{
	test = ft_strjoin(test, "sdf");
}

void	test(void)
{
	/* static char *test = "";

	
	printf("[%s]", test);
	
	
	test2(&test);

	printf("%s", test);
	free(test); */

	char *test = malloc(7);

	printf("%lu", sizeof(test));

}


/* int	main(void)
{
	int	fd = open("tests/elephant_ascii.txt", O_RDONLY);
	char *temp;

	
	while ((temp = get_next_line(fd)))
	{
		printf("%s", temp);
		free(temp);
	}

	system("leaks a.out");
} */

