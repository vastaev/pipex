/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:53 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/01 00:31:53 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(int mode, int fd, t_data data)
{
	if (mode == OUTFILE)
		fd = open(data.argv[data.ind], O_WRONLY | O_CREAT | O_TRUNC, 00774);
	else if (mode == INFILE)
		fd = open(data.argv[1], O_RDONLY, 00774);
	else if (mode == HEREDOC_OUT)
		fd = open(data.argv[data.ind], O_WRONLY | O_CREAT | O_APPEND, 00774);
	if (fd == -1)
		errno_exit(NULL);
	return (fd);
}

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
}

void	redirect(t_data *data, int i, int fdIn)
{
	int	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			errno_exit(NULL);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			errno_exit(NULL);
		close(fd[1]);
		if (fdIn == STDIN_FILENO)
			exit(1);
		else
			run_command(data, i);
	}
}

void	pipex(t_data data)
{
	int	fdin;
	int	fdout;
	int	i;

	i = 0;
	if (data.hereDoc != 1)
	{
		fdout = ft_open(OUTFILE, fdout, data);
		fdin = ft_open(INFILE, fdin, data);
		if (dup2(fdin, STDIN_FILENO) == -1 || dup2(fdout, STDOUT_FILENO) == -1)
			errno_exit(NULL);
		redirect(&data, 0, fdin);
	}
	else
	{
		redirect_heredoc(data);
		fdout = ft_open(HEREDOC_OUT, fdout, data);
		if (dup2(fdout, STDOUT_FILENO) == -1)
			errno_exit(NULL);
	}
	while (i < (data.cntCmnds - 2))
		redirect(&data, i++, 1);
	run_command(&data, data.cntCmnds - 1);
}
