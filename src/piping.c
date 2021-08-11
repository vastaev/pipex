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
	tmpCmnd =  data->cmnds[i][0];
	while (get_next_path(data, ind, i, tmpCmnd))
	{
		if (access(data->cmnds[i][0], F_OK) == 0)
			if (access(data->cmnds[i][0], X_OK) == 0)
				if (execve(data->cmnds[i][0], data->cmnds[i], data->envp) == -1)
					errno_exit(NULL);
		ind--;
	}
}

void	pipe_in(t_data data, int *fd, int in)
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		errno_exit(NULL);
	if (dup2(in, STDIN_FILENO))
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
	if (dup2(out, STDOUT_FILENO))
		errno_exit(NULL);
	close(fd[0]);
	close(out);
	run_command(&data, 1);
}

void	pipex(t_data data)
{
//	int	pids[data.cntCmnds];
//	int	pipes[data.cntCmnds + 1][2];
//	int	i;
//	int	j;
//	int in;
//	int out;
//
//	i = 0;
//	while (i < data.cntCmnds + 1)
//	{
//		if (pipe(pipes[i]) == -1)
//			errno_exit(NULL);
//		i++;
//	}
//	i = 0;
//	while (i < data.cntCmnds)
//	{
//		pids[i] = fork();
//		if (pids[i] == -1)
//			errno_exit(NULL);
//		if (pids[i] == 0)
//		{
//			j = 0;
//			while (j < data.cntCmnds + 1)
//			{
//				if (i != j)
//					close(pipes[j][0]);
//				if (i + 1 != j)
//					close(pipes[j][1]);
//				j++;
//			}
//			dup2(pipes[i][0], STDIN_FILENO);
//			dup2(pipes[i + 1][1], STDOUT_FILENO);
//			run_command(&data, i);
//			close(pipes[i][0]);
//			close(pipes[i + 1][1]);
//			return;
//		}
//		i++;
//	}
//	j = 0;
//	while (j < data.cntCmnds + 1)
//	{
//		if (j != data.cntCmnds)
//			close(pipes[j][0]);
//		if (j != 0)
//			close(pipes[j][1]);
//		j++;
//	}
//	in = open(data.argv[1], O_RDONLY, 0644);
//	dup2(in, STDIN_FILENO);
////	dup2(pipes[0][1], STDOUT_FILENO);
//	dup2(pipes[data.cntCmnds - 1][1], STDIN_FILENO);
//	out = open(data.argv[data.ind], O_WRONLY | O_CREAT | O_TRUNC, 0774);
//	dup2(out, STDOUT_FILENO);
//	i = 0;
//	while (i++ < data.cntCmnds)
//		waitpid(pids[i], NULL, 0);
	int pid;
	int fd[2];
	int	in;
	int	out;

	in = open(data.argv[1], O_RDONLY);
	if (in == -1)
		errno_exit(NULL);
	out = open(data.argv[data.ind], O_WRONLY | O_CREAT | O_TRUNC);
	if (out == -1)
		errno_exit(NULL);
	if (pipe(fd) == -1)
		errno_exit(NULL);
	pid = fork();
	if (pid == -1)
		errno_exit(NULL);
	if (pid == 0)
		pipe_out(data, fd, out);
	else
		pipe_in(data, fd, in);
	wait(0);
}
