/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:37:53 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:37:54 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part1
#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			shag;
	long long	res;
	int			minus;

	minus = 0;
	res = 0;
	shag = 0;
	while (ft_isspace(str[shag]))
		shag++;
	if (str[shag] == '-')
		minus = 1;
	if ((str[shag] == '-') || (str[shag] == '+'))
		shag++;
	while (ft_isdigit(str[shag]))
	{
		res = res * 10 + (str[shag] - '0');
		shag++;
	}
	if (minus == 1)
		return (-res);
	else
		return (res);
}
