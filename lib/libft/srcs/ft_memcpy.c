/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:38:54 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:38:55 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part1 ??
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;

	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	if (dest == 0 && sourc == 0)
		return (0);
	while (n--)
		*dest++ = *sourc++;
	return (dst);
}
