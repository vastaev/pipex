/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:37:21 by cjoanne           #+#    #+#             */
/*   Updated: 2021/09/12 16:03:26 by cjoanne          ###   ########.fr       */
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
	OUTAPPEND = 3,
	INHEREDOC = 4
};

typedef struct s_redir
{
	int				type;
	char			*fileName;
	struct s_redir	*next;
}					t_redir;

typedef struct s_data
{
	char	**argv;
	char	**envp;
	char	***cmnds;
	int		pipesNum;
	char	**paths;
	int		pathsLen;
	int		fdin;
	int		fdout;
	bool	hereDoc;
	t_redir	*redirects;
}			t_data;

void	error_exit(char *str, int exitCode);
void	errno_exit(char *name);
void	parse_paths(t_data *data);
void	parse_commands(t_data *data);
void	pipex(t_data data);
void	redirect_heredoc(t_data data, char *stopWord);
int		ft_open(t_data *data, t_redir *ptr);

t_redir	*new_redirect(int t, char *fName);
void	add_redirect(t_redir **lst, t_redir *new);

#endif
