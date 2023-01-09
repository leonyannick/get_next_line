/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:46:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/06 23:11:17 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*addr;

	addr = (char *) s;
	while (n)
	{
		*addr = c;
		addr++;
		n--;
	}
	return ((char *) s);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s != 0)
	{
		length++;
		s++;
	}
	return (length);
}

/*
	-returns pointer to first occurence of c in s
	-character = byte 
	-returns pointer to matched char or NULL if not found
	-term. 0 is considered part of the string
	
	casting int c to unsigned char
*/
char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char) c;
	while (*s != 0)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (c == 0 && *s == 0)
		return ((char *) s);
	return (0);
}

/*
	DESCRIPTION: copies up to size - 1 characters to dest
			null terminate result as long as at size > 0
	USAGE: null should be included in size, src must be null terminated
	RETURN: length of string trying to create (length of src)
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (0 < (size - 1) && *src != 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = 0;
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*ret;
	char	*ret_start;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = malloc(len1 + len2 + 1);
	if (ret == 0)
		return (0);
	ret_start = ret;
	while (*s1 != 0)
	{
		*ret = *s1;
		ret++;
		s1++;
	}
	ft_strlcpy(ret, s2, len2 + 1);
	return (ret_start);
}

/*
	DESC: returns pointer to new string (duplicate of s)
	RETURN:	pointer
			NULL if insufficient memory
*/
char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = 0;
	return (dup);
}

/*
	RETURN:
		The substring.
		NULL if the allocation fails.
	DESC:
		Allocates (with malloc(3)) and returns a substring
		from the string ’s’.
		The substring begins at index ’start’ and is of
		maximum size ’len’.
	PARAMS:
		s:  The string from which to create the substring.
		start:  The start index of the substring in the
		string ’s’.
		len:  The maximum length of the substring.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
