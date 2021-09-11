/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:46:21 by nephilister       #+#    #+#             */
/*   Updated: 2021/09/11 15:24:22 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_data(int argc, char *argv[], char *envp[], t_data *data)
{
	data->cmnds = malloc(sizeof(*data->cmnds) * 10);
	if (data->cmnds == NULL)
		error_exit("Malloc error", 2);
	data->argv = argv;
	data->envp = envp;
}

void	validation_of_args(int argc, char *argv[], t_data *data)
{
	int	i;

	i = 0;
	data->fdin = 0;
	data->fdout = 1;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], ">>") == 0)
		{
			if (argv[i + 1])
				data->stopWord = argv[i + 1];
			redirect_heredoc(*data);
		}
		if (ft_strcmp(argv[i], ">"))
			if (argv[i + 1])
				add_redirect(data->redirects, new_redirect(OUTFILE, argv[i + 1]));
		if (ft_strcmp(argv[i], "<"))
			if (argv[i + 1])
				add_redirect(data->redirects, new_redirect(INFILE, argv[i + 1]));
		if (ft_strcmp(argv[i], ">>"))
			if (argv[i + 1])
				add_redirect(data->redirects, new_redirect(OUTAPPEND, argv[i + 1]));
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
