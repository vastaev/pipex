/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:39:51 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:39:52 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*update_tail(char *tail)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (tail[i] != '\n' && tail[i])
		i++;
	if (tail[i] == '\0')
	{
		free(tail);
		return (NULL);
	}
	i++;
	tmp = tail;
	tail = (char *)malloc(sizeof(char) * (get_ft_strlen(tail) - i) + 1);
	if (NULL == tail)
		return (NULL);
	while (tmp[i])
		tail[j++] = tmp[i++];
	tail[j] = '\0';
	free(tmp);
	return (tail);
}

static char	*check_tail(char *tail, char **line)
{
	char	*a;

	a = "42";
	if (get_ft_strchr(tail, '\n'))
	{
		*line = get_ft_strdupchr(tail, '\n');
		if (NULL == *line)
			return (NULL);
		tail = update_tail(tail);
		return (tail);
	}
	else if (get_ft_strchr(tail, '\0'))
	{
		*line = get_ft_strdupchr(tail, '\0');
		if (NULL == *line)
			return (NULL);
		free(tail);
	}
	return (a);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*tail;
	int			ret;
	char		*tmp;

	if (fd < 0 || read(fd, 0, 0) < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	while (!get_ft_strchr(tail, '\n') && ret > 0)
	{
		ret = (int)read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		tmp = tail;
		tail = get_ft_strjoin(tail, buf);
		if (NULL == tail || ret == -1)
			return (-1);
		if (tmp != NULL)
			free(tmp);
	}
	tail = check_tail(tail, line);
	if (NULL == tail)
		return (-1);
	if (ret == 0)
		tail = NULL;
	return (ret != 0);
}
