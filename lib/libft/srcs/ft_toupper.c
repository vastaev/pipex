/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:11:08 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/31 01:11:09 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part1
#include "libft.h"

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c = c - 32;
	return (c);
}
