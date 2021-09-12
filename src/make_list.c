/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 04:24:51 by nephilister       #+#    #+#             */
/*   Updated: 2021/09/12 12:39:01 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_redir	*new_redirect(int t, char *fName)
{
	t_redir	*new;
	
	new = malloc(sizeof(t_redir));
	new->type = t;
	new->fileName = fName;
	new->next = NULL;
	return (new);
}

void	add_redirect(t_redir **lst, t_redir *new)
{
	t_redir *ptr;
	
	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;		
		ptr->next = new;
	}
}