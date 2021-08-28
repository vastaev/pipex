/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:38:57 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:38:58 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part1
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	*ldest;
	unsigned char	*lsource;

	if (dst == 0 && src == 0)
		return (0);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	ldest = dest + (len - 1);
	lsource = source + (len - 1);
	if (dest < source)
		while (len--)
			*dest++ = *source++;
	else
		while (len--)
			*ldest-- = *lsource--;
	return (dst);
}
