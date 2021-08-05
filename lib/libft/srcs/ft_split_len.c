#include "libft.h"

int	ft_split_len(char **s)
{
	int	counter;

	counter = 0;
	while (s[counter] != NULL)
		counter++;
	return (counter);
}
