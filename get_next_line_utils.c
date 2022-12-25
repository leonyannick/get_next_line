/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:46:45 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/25 00:27:10 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	DESC: fills first n bytes of memory area (pointed to by s) with constant byte c
	RETURN: returns pointer to memory area
	TESTS: -
*/
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
	return (s);
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
