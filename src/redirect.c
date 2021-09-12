/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:36:44 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/12 11:16:06 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	input_taking(int *fd, char *stopWord)
{
	char	*line;
	char	*tmp;

	close(fd[0]);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		get_next_line(0, &line);
		if (ft_strcmp(line, stopWord) == 0)
			break ;
		tmp = line;
		free(tmp);
		line = ft_strjoin(line, "\n");
		if (line)
			write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	exit(0);
}

void	redirect_heredoc(t_data data, char *stopWord)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		errno_exit(NULL);
	pid = fork();
	if (pid == -1)
		errno_exit(NULL);
	if (pid == 0)
		input_taking(fd, stopWord);
	close(fd[1]);
	// if (dup2(fd[0], STDIN_FILENO) == -1)
	// 	errno_exit(NULL);
	// close(fd[0]);
	wait(NULL);
}
