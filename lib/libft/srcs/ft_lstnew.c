/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:38:43 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:38:44 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//bonus
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelem;

	newelem = (t_list *)malloc(sizeof(t_list));
	if (newelem == 0)
		return (0);
	newelem->content = content;
	newelem->next = NULL;
	return (newelem);
}
