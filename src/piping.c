/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:56 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/03 03:37:39 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_next_path(t_data *data, int ind, int i, char *cmnd)
{
	char	*tmp;

	if (ind >= 0)
	{
		tmp = ft_strjoin(data->paths[ind], "/");
		data->cmnds[i][0] = cmnd;
		data->cmnds[i][0] = ft_strjoin(tmp, cmnd);
		return (1);
	}
	else
		return (0);
}

void	run_command(t_data *data, int i)
{
	int		ind;
	char	*tmpCmnd;

	ind = data->pathsLen - 1;
	tmpCmnd = data->cmnds[i][0];
	while (get_next_path(data, ind, i, tmpCmnd))
	{
		if (access(data->cmnds[i][0], F_OK) == 0)
			if (access(data->cmnds[i][0], X_OK) == 0)
				if (execve(data->cmnds[i][0], data->cmnds[i], data->envp) == -1)
					errno_exit(NULL);
		ind--;
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(tmpCmnd, 2);
	ft_putstr_fd("\n", 2);
	exit(5);
}

void	pipe_in(t_data data, int *fd, int in)
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		errno_exit(NULL);
	if (dup2(in, STDIN_FILENO) == -1)
		errno_exit(NULL);
	close(fd[1]);
	close(in);
	run_command(&data, 0);
}

void	pipe_out(t_data data, int *fd, int out)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		errno_exit(NULL);
	if (dup2(out, STDOUT_FILENO) == -1)
		errno_exit(NULL);
	close(fd[0]);
	close(out);
	run_command(&data, 1);
}

void	pipex(t_data data)
{
	int	pid;
	int	fd[2];
	int	in;
	int	out;

	in = open(data.argv[1], O_RDONLY, 00774);
	if (in == -1)
		errno_exit(NULL);
	out = open(data.argv[data.ind], O_WRONLY | O_CREAT | O_TRUNC, 00774);
	if (out == -1)
		errno_exit(NULL);
	if (pipe(fd) == -1)
		errno_exit(NULL);
	pid = fork();
	if (pid == -1)
		errno_exit(NULL);
	if (pid == 0)
		pipe_in(data, fd, in);
	wait(NULL);
	pipe_out(data, fd, out);
}
