/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:39:15 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/28 12:39:16 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**tostrings(const char *s, char c, char **strings);
static int	stringlen(const char *s, char c, int step);
static int	wordscount(const char *s, char c);
static char	**malloc_error_free(char **strings, size_t sindx);

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	strnum;

	if (!s)
		return (NULL);
	strnum = wordscount(s, c);
	strings = (char **)malloc(sizeof(char *) * (strnum + 1));
	if (strings == NULL)
		return (NULL);
	tostrings(s, c, strings);
	return (strings);
}

static int	wordscount(const char *s, char c)
{
	size_t	step;
	int		counter;
	char	ccheck;

	step = 0;
	counter = 0;
	ccheck = 1;
	while (s[step])
	{
		if (s[step] != c && ccheck == 1)
		{
			counter++;
			ccheck = 0;
		}
		else if (s[step] == c)
			ccheck = 1;
		step++;
	}
	return (counter);
}

static int	stringlen(const char *s, char c, int step)
{
	while ((s[step] != c) && s[step])
		step++;
	return (step);
}

static char	**tostrings(const char *s, char c, char **strings)
{
	size_t			sindx;
	unsigned int	step;

	step = 0;
	sindx = 0;
	while (s[step])
	{
		while (s[step] && s[step] == c)
			step++;
		if (s[step])
		{
			strings[sindx] = ft_substr(s, step, stringlen(s, c, step) - step);
			if (!strings[sindx])
				return (malloc_error_free(strings, sindx));
			sindx++;
			step = stringlen(s, c, step);
		}
	}
	strings[sindx] = NULL;
	return (strings);
}

static char	**malloc_error_free(char **strings, size_t sindx)
{
	while (sindx--)
	{
		free(strings[sindx]);
		strings[sindx] = NULL;
	}
	free(strings);
	return (NULL);
}
