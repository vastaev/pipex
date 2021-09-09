/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:43 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/09 03:39:02 by nephilister      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(t_data *data)
{
	int	i;
	int	j;
	int k;
	int l;

	k = 0;
	j = 2;
	l = 1;
	while (1)
	{
		data->cmnds[k] = malloc(sizeof(**data->cmnds) * 3);
		data->cmnds[k][0] = data->argv[j - 1];
		while (data->argv[j] != NULL && ft_strcmp(data->argv[j], "|") != 0 )
		{
			data->cmnds[k][l] = data->argv[j];
			j++;
		}
		l = 1;
		data->cmnds[k][2] = NULL;
		if (data->argv[j] == NULL)
			break ;
		j += 2;
		k++;
		// ls -l | wc -l
	}
	// int q = 0;
	// while (q <= k)
	// {
	// 	printf("%s %s %s\n", data->cmnds[q][0], data->cmnds[q][1], data->cmnds[q][2]);
	// 	q++;
	// }
	
	// data->cmnds[0] = malloc(sizeof(**data->cmnds) * 3);
	// data->cmnds[0][0] = data->argv[1];
	// data->cmnds[0][1] = data->argv[2];
	// data->cmnds[0][2] = NULL;
	// data->cmnds[1] = malloc(sizeof(**data->cmnds) * 3);
	// data->cmnds[1][0] = data->argv[4];
	// data->cmnds[1][1] = data->argv[5];
	// data->cmnds[1][2] = NULL;
	// data->cmnds[2] = malloc(sizeof(**data->cmnds) * 3);
	// data->cmnds[2][0] = data->argv[7];
	// data->cmnds[2][1] = data->argv[8];
	// data->cmnds[2][2] = NULL;
	// data->cmnds[3] = malloc(sizeof(**data->cmnds) * 3);
	// data->cmnds[3][0] = data->argv[10];
	// data->cmnds[3][1] = data->argv[11];
	// data->cmnds[3][2] = NULL;
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
