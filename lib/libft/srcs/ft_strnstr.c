/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:39:35 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:39:36 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		step;
	char	*hays;

	hays = (char *)haystack;
	step = 0;
	if (*needle == '\0')
		return (hays);
	while (haystack[step] && len-- >= ft_strlen(needle))
	{
		if (hays[step] == needle[0])
		{
			if (ft_strncmp(&hays[step], needle, ft_strlen(needle)) == 0)
				return (&hays[step]);
		}
		step++;
	}
	return (0);
}
