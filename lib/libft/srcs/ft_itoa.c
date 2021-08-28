/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:38:24 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:38:25 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part2
//receive int, return string
#include "libft.h"

static int	nlen(long n)
{
	int		counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	numlen = nlen(n);
	str = (char *)malloc(sizeof(char) * numlen + 1);
	if (str == NULL)
		return (NULL);
	str[numlen--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n / 10)
	{
		str[numlen] = (n % 10) + 48;
		n = n / 10;
		numlen--;
	}
	str[numlen] = n + '0';
	return (str);
}
