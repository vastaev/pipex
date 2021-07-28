//part1
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				step;
	unsigned char	chr;

	chr = c;
	step = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (step > 0)
	{
		if (s[step] == chr)
			return ((char *)(s + step));
		step--;
	}
	if (s[step] == chr)
		return ((char *)(s + step));
	return (0);
}
