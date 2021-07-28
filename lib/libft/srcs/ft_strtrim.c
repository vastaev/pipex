//p2
#include "libft.h"

static char	findinset(char c, char const *set)
{
	int	step;

	step = 0;
	while (set[step])
	{
		if (set[step] == c)
			return (1);
		step++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	int		step;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	step = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && findinset(s1[start], set))
		start++;
	while (end > start && findinset(s1[end - 1], set))
		end--;
	if (start == 0 && end == ft_strlen(s1))
		return (ft_strdup(s1));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (NULL);
	while (end > start)
		 str[step++] = s1[start++];
	str[step] = '\0';
	return (str);
}
