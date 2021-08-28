/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:39:03 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:39:04 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//part2
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	step;

	step = 0;
	if (s)
	{
		while (s[step])
		{
			write(fd, &s[step], 1);
			step++;
		}
	}
	write(fd, "\n", 1);
}
