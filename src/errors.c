#include "pipex.h"

void	error_exit(char *str, int exitCode)
{
	ft_putstr_fd(str, 2);
	exit(exitCode);
}