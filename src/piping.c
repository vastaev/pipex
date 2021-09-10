/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:30:53 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/10 18:16:31 by nephilister      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(int mode, t_data data)
{
	int	fd;

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
					close(p[0][0]);
					dup2(p[0][1], data.fdout);
				}
				else
				{
					close(p[i - 1][1]);
					dup2(p[i - 1][0], data.fdin);
				}
			}
			else
			{
				close(p[i - 1][1]);
				dup2(p[i - 1][0], 0);
				close(p[i][0]);
				dup2(p[i][1], 1);
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
