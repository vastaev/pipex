/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:38:45 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:38:46 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*ptr;

	if (lst == NULL)
		return (0);
	counter = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		++counter;
		ptr = ptr->next;
	}
	return (counter);
}
