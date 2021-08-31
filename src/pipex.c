/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:49 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/01 00:17:00 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_data(int argc, char *argv[], char *envp[], t_data *data)
{
	data->ind = argc - 1;
	data->cntCmnds = (argc - 3);
	data->cmnds = malloc(sizeof(*data->cmnds) * (data->cntCmnds + 1));
	if (data->cmnds == NULL)
		error_exit("Malloc error\n", 2);
	data->cmnds[data->cntCmnds] = NULL;
	data->infile = argv[1];
	data->outfile = argv[data->ind];
	data->argv = argv;
	data->envp = envp;
}

void	validation_of_args(int argc, char *argv[])
{
	if (argc < 5)
		error_exit("Bad usage! ./pipex file1 cmd1 cmd2 file", 4);
	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		errno_exit(argv[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	validation_of_args(argc, argv);
	initialize_data(argc, argv, envp, &data);
	parse_commands(&data);
	parse_paths(&data);
	pipex(data);
	return (0);
}
