//part1
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			step;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	step = 0;
	while (step < n)
	{
		dest[step] = source[step];
		if (dest[step] == (unsigned char) c)
			return ((void *)(dst + step + 1));
		step++;
	}
	return (0);
}
