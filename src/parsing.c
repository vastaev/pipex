/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:43 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/12 17:34:03 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(t_data *data)
{
	// int	j;
	// int	k;
	// int	l;

	// k = 0;
	// j = 2;
	// while (1)
	// {
	// 	l = 1;
	// 	data->cmnds[k] = malloc(sizeof(**data->cmnds) * 3);
	// 	data->cmnds[k][0] = data->argv[j - 1];
	// 	while (data->argv[j] != NULL && ft_strcmp(data->argv[j], "|") != 0)
	// 	{
	// 		data->cmnds[k][l] = data->argv[j];
	// 		l++;
	// 		j++;
	// 	}
	// 	data->cmnds[k][l] = NULL;
	// 	if (data->argv[j] == NULL)
	// 		break ;
	// 	j += 2;
	// 	k++;
	// }
	// data->pipesNum = k;
	data->cmnds[0] =  malloc(sizeof(**data->cmnds) * 3);;
	data->cmnds[0][0] = data->argv[3];
	data->cmnds[0][1] = NULL;
	data->cmnds[1] =  malloc(sizeof(**data->cmnds) * 3);;
	data->cmnds[1][0] = data->argv[5];
	data->cmnds[1][1] = NULL;
	data->pipesNum = 1;
}

void	parse_paths(t_data *data)
{
	int	i;

	i = 0;
	while (ft_strncmp(data->envp[i], "PATH=", 5) != 0)
		i++;
	data->paths = ft_split(data->envp[i] + 5, ':');
	if (!data->paths)
		error_exit("Malloc error\n", 3);
	data->pathsLen = ft_split_len(data->paths);
}
