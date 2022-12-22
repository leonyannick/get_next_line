/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:46:45 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/22 19:24:42 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
