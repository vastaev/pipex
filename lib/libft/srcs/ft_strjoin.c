/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:39:23 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:39:24 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part2
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concstr;

	if (!s1 || !s2)
		return (NULL);
	concstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concstr == NULL)
		return (NULL);
	ft_memcpy(concstr, s1, ft_strlen(s1));
	ft_memcpy(concstr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (concstr);
}
