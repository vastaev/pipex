#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/errno.h>

typedef struct s_data
{
	char	**argv;
	int		cntCmnds;
	int		ind;
	char	**envp;
	char	*infile;
	char	*outfile;
	char	***cmnds;
	char	**paths;
	int		pathsLen;
	int		hereDoc;
} t_data;

void	error_exit(char *str, int exitCode);
void	errno_exit(char *name);
void	parse_paths(t_data *data);
void	parse_commands(t_data *data);
void	pipex(t_data data);


#endif
