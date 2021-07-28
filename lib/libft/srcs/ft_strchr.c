//part1
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = c;
	if (s)
	{
		while (*s != chr)
			if (*s++ == '\0')
				return (0);
	}
	return ((char *)s);
}
