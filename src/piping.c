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

void	pipex(t_data data)
{
//	int	pids[data.cntCmnds];
//	int	pipes[data.cntCmnds + 1][2];
//	int	i;
//	int	j;
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
//				run_command(&data, 0);
//				return;
//			}
//		}
//	}
	int pid;

	pid = fork();
	if (pid == 0)
	{

		run_command(&data, 0);
		return;
	}
	wait(0);
}

//void pohut(t_data data)
//{
//
//}