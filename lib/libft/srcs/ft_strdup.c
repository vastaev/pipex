#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*scopy;

	len = (int)ft_strlen(s1);
	scopy = malloc(len + 1);
	if (scopy == NULL)
		return (NULL);
	ft_memcpy(scopy, s1, len + 1);
	return (scopy);
}
