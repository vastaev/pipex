#include "pipex.h"

void	errno_exit(char *name)
{
	char	*error_msg;

	write(2, "pipex: ", 7);
	error_msg = strerror(errno);
	write(2, error_msg, ft_strlen(error_msg));
	if (name)
	{
		write(2, ": ", 2);
		ft_putstr_fd(name, 2);
	}
	write(2, "\n", 1);
	exit(errno);
}

void	error_exit(char *str, int exitCode)
{
	ft_putstr_fd(str, 2);
	exit(exitCode);
}