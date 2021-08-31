/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:36:44 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:36:45 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	input_taking(t_data data, int *fd)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		get_next_line(0, &line);
		if (ft_strcmp(line, data.argv[2]) == 0)
			break ;
		line = ft_strjoin(line, "\n");
		if (line)
			write(fd[1], line, ft_strlen(line));
	}
	close(fd[0]);
	close(fd[1]);
	exit(0);
}

void	redirect_heredoc(t_data data)
{
	int	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid)
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
	else
		input_taking(data, fd);
}