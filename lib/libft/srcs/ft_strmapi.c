//part2 ?? str len
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	step;
	char			*str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	step = 0;
	while (s[step])
	{
		str[step] = f(step, s[step]);
		step++;
	}
	str[step] = '\0';
	return (str);
}
