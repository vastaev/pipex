/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:53 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/12 18:43:51 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(t_data *data, t_redir *ptr)
{
	int	pid;
	int	wStatus;
	int	statusCode;

	// pid = fork();
	// // if (pid == -1) error
	// if (pid == 0)
	// {
		if (ptr->type == OUTFILE)
			data->fdout = open(ptr->fileName, O_WRONLY | O_CREAT | O_TRUNC, 00774);
		else if (ptr->type == INFILE)
			data->fdin = open(ptr->fileName, O_RDONLY, 00774);
		else if (ptr->type == OUTAPPEND)
			data->fdout = open(ptr->fileName, O_WRONLY | O_CREAT | O_APPEND, 00774);
		if (data->fdin < 0 || data->fdout < 0)
			errno_exit(NULL);
		// exit(0);
	// }
	// wait(&wStatus);
	// if (WIFEXITED(wStatus))
	// {
	// 	statusCode = WEXITSTATUS(wStatus);
	// 	if (statusCode != 0)
	// 		return (1);
	// }
	return (0);
}

int	get_next_path(t_data *data, int ind, int i, char *cmnd)
{
	char	*tmp;

	if (ind >= 0)
	{
		tmp = ft_strjoin(data->paths[ind], "/");
		data->cmnds[i][0] = cmnd;
		data->cmnds[i][0] = ft_strjoin(tmp, cmnd);
		free(tmp);
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

void	pipex(t_data data)
{
	int		i;
	pid_t	pid;
	int		**p;

	p = malloc((sizeof(int *) * data.pipesNum));
	i = 0;
	while(i < data.pipesNum)
	{
		p[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < data.pipesNum)
	{
		pipe(p[i]);
		i++;
	}
	i = 0;
	while (i <= data.pipesNum)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0 || i == data.pipesNum)
			{
				if (i == 0)
				{
					if (data.fdin)
						dup2(data.fdin, STDIN_FILENO);
					close(p[0][0]);
					dup2(p[0][1], STDOUT_FILENO);
				}
				else
				{
					if (data.fdout)
						dup2(data.fdout, STDOUT_FILENO);
					close(p[i - 1][1]);
					dup2(p[i - 1][0], STDIN_FILENO);
				}
			}
			else
			{
				close(p[i - 1][1]);
				dup2(p[i - 1][0], STDIN_FILENO);
				close(p[i][0]);
				dup2(p[i][1], STDOUT_FILENO);
			}
			run_command(&data, i);
		}
		if (i < data.pipesNum)
			close(p[i][1]);
		i++;
	}
	i = 0;
	while (i < data.pipesNum)
	{
		close(p[i][0]);
		i++;
	}
	i = 0;
	while (i <= data.pipesNum)
	{
		wait(NULL);
		i++;
	}
	return ;
}
