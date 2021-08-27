#include "libft.h"

void	ft_free_split(char **s)
{
	int	len;

	len = ft_split_len(s);
	while (len--)
	{
		free(s[len]);
		s[len] = NULL;
	}
	free(s);
	s = NULL;
}
