//part1
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	step;

	step = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[step] != '\0' && step < (dstsize - 1))
	{
		dst[step] = src[step];
		step++;
	}
	dst[step] = '\0';
	return (ft_strlen(src));
}
