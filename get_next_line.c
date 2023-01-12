/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:24 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/09 18:03:01 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*gnl_free(char **stash, char *buffer, char *line)
{
	if (*stash)
	{
		free (*stash);
		*stash = 0;
	}	
	if (buffer)
		free (buffer);
	if (line)
		free (line);
	return (NULL);
}

static char	*gnl_join(char **stash, char *buffer)
{
	char	*temp;

	if (!*stash)
		*stash = ft_substr(buffer, 0, BUFFER_SIZE);
	else
	{
		temp = *stash;
		*stash = ft_strjoin(*stash, buffer);
		free(temp);
	}
	return (*stash);
}

static char	*gnl_save(char **stash)
{
	char	*line;
	size_t	line_len;
	size_t	stash_len_remain;
	char	*nl_idx;
	char	*temp;

	nl_idx = ft_strchr(*stash, '\n');
	if (!nl_idx)
		stash_len_remain = 0;
	else
		stash_len_remain = ft_strlen(nl_idx + 1);
	line_len = ft_strlen(*stash) - stash_len_remain;
	line = ft_substr(*stash, 0, line_len);
	temp = *stash;
	*stash = ft_substr(*stash, line_len, stash_len_remain);
	free(temp);
	if (!*stash)
		return (gnl_free(stash, NULL, line));
	return (line);
}

static char	*gnl_parse(int fd, char **stash, char *buffer)
{
	ssize_t	read_ret;

	while (!ft_strchr(buffer, '\n'))
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (!read_ret && !ft_strlen(*stash))
			return (gnl_free(stash, buffer, NULL));
		*stash = gnl_join(stash, buffer);
		if (!*stash)
			return (gnl_free(stash, buffer, NULL));
		if (read_ret < BUFFER_SIZE)
			break ;
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
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (gnl_free(&stash, buffer, NULL));
	return (gnl_parse(fd, &stash, buffer));
}

/* #include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	//printf("%s", argv[1]);
	if (argc < 2)
		return (1);
	int	fd = open(argv[1], O_RDONLY);
	char *temp;

	
	while ((temp = get_next_line(fd)))
	{
		printf("%s", temp);
		free(temp);
	}

	//system("leaks a.out");
} */
