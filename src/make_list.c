/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 04:24:51 by nephilister       #+#    #+#             */
/*   Updated: 2021/09/10 19:02:43 by nephilister      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_redir	*new_redirect(int t)
{
	t_redir	*new;
	
	new = malloc(sizeof(t_redir));
	new->type = t;
	new->next = NULL;
}

void	add_redirect(t_redir **lst, t_redir *new)
{
	t_redir *ptr;
	
	if (lst == NULL)
		*lst = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;		
		ptr->next = new;
	}
}