//part1 ??
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
