/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:46:21 by nephilister       #+#    #+#             */
/*   Updated: 2021/08/28 07:07:55 by nephilister      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* TODO правильный возврат ошибки после execve
 * название файла ``...'' такой же как ввод комманды
 */

void	initialize_data(int argc, char *argv[], char *envp[], t_data *data)
{
	data->ind = argc - 1;
	data->cntCmnds = (argc - 3) / 2;
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
	if (argc < 7)
		error_exit("Wrong usage, not enough args", 1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		return ;
	else if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		errno_exit(argv[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	char *line;
	char *text;


	// while (1)
	// {
	// 	// ft_putstr_fd("heredoc> ", 1);
	// 	get_next_line(0, &line);
	// 	if (ft_strcmp(line, argv[1]) == 0)
	// 		break;
	// 	line = ft_strjoin(line, "\n");
	// 	text = ft_strjoin(text, line);
	// }
	// printf("%s", text);
	validation_of_args(argc, argv);
	initialize_data(argc, argv, envp, &data);
	parse_commands(&data);
	parse_paths(&data);
	pipex(data);
    return 0;
}
