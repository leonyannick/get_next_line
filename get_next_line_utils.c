/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:46:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/03 09:25:14 by lbaumann         ###   ########.fr       */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*addr;

	if (nmemb * size > SIZE_T_MAX)
		return (0);
	addr = malloc(nmemb * size);
	if (addr == 0)
		return (0);
	ft_memset(addr, 0, (nmemb * size));
	return (addr);
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
	-size = full size of buffer
	-src and dst have to be NULL terminated
	-appends src at end of dst
	-appends at most size - strlen(dst) - 1 bytes
	-returns: initial length of dst + length of src
	-if traversed size characters without finding NULL, no NULL termination
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (*dst != 0)
	{
		dst++;
		size--;
	}
	while ((size - 1) > 0 && *src != 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = 0;
	return (dst_len + src_len);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (start);
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

