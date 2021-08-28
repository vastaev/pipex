/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:53 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 11:43:29 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_taking(t_data data, int *fd);

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
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
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

	i = 1;
	if (data.hereDoc != 1)
	{
		fdin = open(data.argv[1], O_RDONLY, 00774);
		dup2(fdin, STDIN_FILENO);
		redirect(&data, 0, fdin);
	}
	else
		redirect_heredoc(data);
	fdout = open(data.argv[data.ind], O_WRONLY | O_CREAT | O_TRUNC, 00774);
	dup2(fdout, STDOUT_FILENO);
	while (i < (data.cntCmnds - 1))
	{
		redirect(&data, i, 1);
		i++;
	}
	run_command(&data, data.cntCmnds - 1);
}
