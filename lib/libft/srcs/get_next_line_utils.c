#include "libft.h"

static void	*get_ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;

	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	if (dest == 0 && sourc == 0)
		return (0);
	while (n--)
		*dest++ = *sourc++;
	return (dst);
}

int	get_ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	if (!s)
		return (0);
	chr = c;
	while (*s != chr)
		if (*s++ == '\0')
			return (0);
	return (1);
}

size_t	get_ft_strlen(const char *s)
{
	size_t	counter;

	if (!s)
		return (0);
	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*get_ft_strdupchr(const char *s1, unsigned char c)
{
	char	*scopy;
	int		i;

	i = 0;
	while (s1[i] != c && s1[i])
		i++;
	scopy = malloc(i + 1);
	if (scopy == NULL)
		return (NULL);
	if (c == '\0')
		get_ft_memcpy(scopy, s1, i + 1);
	else
	{
		get_ft_memcpy(scopy, s1, i);
		scopy[i] = '\0';
	}
	return (scopy);
}

char	*get_ft_strjoin(char const *s1, char const *s2)
{
	char	*concstr;
	int		i;
	int		j;
	int		first_len;
	int	 	second_len;

	i = 0;
	j = 0;
	first_len = (int)get_ft_strlen(s1);
	second_len = (int)get_ft_strlen(s2);
	concstr = malloc(sizeof(char) * (first_len + second_len) + 1);
	if (concstr == NULL)
		return (NULL);
	while (i < first_len)
	{
		concstr[i] = s1[i];
		i++;
	}
	while (j < second_len)
		concstr[i++] = s2[j++];
	concstr[i] = '\0';
	return (concstr);
}
