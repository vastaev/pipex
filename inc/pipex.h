#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/errno.h>

typedef struct s_data
{
	char	**argv;
	int		cntCmnds;
	char	**envp;
	char	*infile;
	char	*outfile;
	char	***cmnds;
	char	**paths;
} t_data;

void	error_exit(char *str, int exitCode);


#endif
