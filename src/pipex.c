/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:46:21 by nephilister       #+#    #+#             */
/*   Updated: 2021/09/09 03:30:20 by nephilister      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_data(int argc, char *argv[], char *envp[], t_data *data)
{
	data->ind = argc - 1;
	data->cmnds = malloc(sizeof(*data->cmnds) * 10);
	if (data->cmnds == NULL)
		error_exit("Malloc error", 2);
	data->argv = argv;
	data->envp = envp;
}

void	validation_of_args(int argc, char *argv[], t_data *data)
{
	//если в спаршенной строке есть какой-то из символов пайпа, то передавать флаги
	int i;

	i = 0;
	data->fdin = 0;
	data->fdout = 1;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "<<") == 0)
			data->fdin =  data->hereDoc = 1;
		else if (argv[i][0] == '<')
		{
			if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
				errno_exit(argv[1]);
			data->fdin = ft_open(INFILE, *data);
		}
		else if (argv[i][0] == '>')
			data->fdout = ft_open(OUTFILE, *data);
		else if (ft_strcmp(argv[i], ">>") == 0)
			data->fdout = ft_open(HEREDOC_OUT, *data);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	validation_of_args(argc, argv, &data);
	initialize_data(argc, argv, envp, &data);
	parse_commands(&data);
	parse_paths(&data);
	pipex(data);
	return (0);
}
