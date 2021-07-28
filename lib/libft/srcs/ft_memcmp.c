//part 1
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				shag;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	shag = 0;
	while (n--)
	{
		if (str1[shag] - str2[shag] != 0)
			return (str1[shag] - str2[shag]);
		shag++;
	}
	return (0);
}
