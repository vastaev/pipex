/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:39:33 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:39:34 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part1
#include "libft.h"

static int	ft_charcmp(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	step;

	if (n == 0)
		return (0);
	step = 0;
	while (step < n)
	{
		if (!ft_charcmp(s1[step], s2[step]))
			return ((unsigned char)s1[step] - (unsigned char)s2[step]);
		if ((s1[step] == 0) || (s2[step] == 0))
			break ;
		step++;
	}
	return (0);
}
