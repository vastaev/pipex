/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:37:21 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/31 15:56:33 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/errno.h>

enum e_openmode
{
	INFILE = 1,
	OUTFILE = 2,
	HEREDOC_OUT = 3
};

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
}	t_data;

void	error_exit(char *str, int exitCode);
void	errno_exit(char *name);
void	parse_paths(t_data *data);
void	parse_commands(t_data *data);
void	pipex(t_data data);
void	redirect_heredoc(t_data data);

#endif
