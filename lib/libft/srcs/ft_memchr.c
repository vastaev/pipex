//part1
#include "libft.h"

static int	ft_charcmp(unsigned char c1, unsigned char c2)
{
	if (c1 == c2)
		return (1);
	else
		return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*str;
	size_t			step;

	step = 0;
	str = (unsigned char *)s;
	chr = (unsigned char) c;
	while (step < n)
	{
		if (ft_charcmp(str[step], chr))
			return (&str[step]);
		step++;
	}
	return (0);
}
