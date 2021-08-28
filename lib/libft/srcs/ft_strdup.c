/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:39:21 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:39:22 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*scopy;

	len = (int)ft_strlen(s1);
	scopy = malloc(len + 1);
	if (scopy == NULL)
		return (NULL);
	ft_memcpy(scopy, s1, len + 1);
	return (scopy);
}
