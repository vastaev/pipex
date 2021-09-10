/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 04:24:51 by nephilister       #+#    #+#             */
/*   Updated: 2021/09/10 18:20:22 by nephilister      ###   ########.fr       */
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

