/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:39:31 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:39:33 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part2 ?? str len
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	step;
	char			*str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	step = 0;
	while (s[step])
	{
		str[step] = f(step, s[step]);
		step++;
	}
	str[step] = '\0';
	return (str);
}
