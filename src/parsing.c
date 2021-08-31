/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:43 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/31 01:12:18 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(t_data *data)
{
	int	i;
	int	j;

	if (data->hereDoc == 1)
		j = 1;
	else
		j = 0;
	i = 0;
	while (i < data->cntCmnds)
	{
		data->cmnds[i] = malloc(sizeof(**data->cmnds) * 3);
		data->cmnds[i][0] = data->argv[j + 2];
		data->cmnds[i][1] = data->argv[j + 3];
		data->cmnds[i][2] = NULL;
		j += 2;
		i++;
	}
}

void	parse_paths(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (ft_strncmp(data->envp[i], "PATH=", 5) != 0)
		i++;
	data->paths = ft_split(data->envp[i] + 5, ':');
	if (!data->paths)
		error_exit("Malloc error\n", 3);
	data->pathsLen = ft_split_len(data->paths);
}
