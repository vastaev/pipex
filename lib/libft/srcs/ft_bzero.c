//part1
#include "libft.h" 

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)s;
	while (n--)
		*dest++ = '\0';
}
