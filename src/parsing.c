/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:43 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/08 00:24:06 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(t_data *data)
{
	// int	i;
	// int	j;
	// int k;

	// k = 0;
	// i = 1;
	// j = 2;
	// while (data->argv[j] != '\0')
	// {
	// 	data->cmnds[k][0] = data->argv[i];
	// 	while (data->argv[j][0] != '|' || data->argv[j] != '\0')
	// 	{
	// 		data->cmnds[k][j] = data->argv[j];
	// 		j++;
	// 	}
	// 	if (data->argv[j] == '\0')
	// 		break ;
	// 	i = j + 1;
	// 	j += 2;
	// 	k++;
	// 	// ls -l | wc -l
	// }
	// int q = 0;
	// while (q < 2)
	// {
	// 	printf("%s %s\n", data->cmnds[q][0], data->cmnds[q][1]);
	// 	q++;
	// }
	data->cmnds[0] = malloc(sizeof(**data->cmnds) * 3);
	data->cmnds[0][0] = data->argv[1];
	data->cmnds[0][1] = data->argv[2];
	data->cmnds[0][2] = NULL;
	data->cmnds[1] = malloc(sizeof(**data->cmnds) * 3);
	data->cmnds[1][0] = data->argv[4];
	data->cmnds[1][1] = data->argv[5];
	data->cmnds[1][2] = NULL;
	// int q = 0;
	// while (q < 2)
	// {
	// 	printf("%s %s\n", data->cmnds[q][0], data->cmnds[q][1]);
	// 	q++;
	// }
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
