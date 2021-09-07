/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:37:21 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/07 12:15:52 by nephilister      ###   ########.fr       */
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

typedef struct s_pipeflags
{
	bool	filein;
	bool	fileout;
	bool	here_doc;
	bool	appendf;
}			t_pipeflags;

typedef struct s_data
{
	char		**argv;
	int			cntCmnds;
	int			ind;
	char		**envp;
	char		***cmnds;
	char		**paths;
	int			pathsLen;
	int			fdin;
	int			fdout;
	t_pipeflags	flags;
}	t_data;

void	error_exit(char *str, int exitCode);
void	errno_exit(char *name);
void	parse_paths(t_data *data);
void	parse_commands(t_data *data);
void	pipex(t_data data);
void	redirect_heredoc(t_data data);
int		ft_open(int mode, t_data data);


#endif
