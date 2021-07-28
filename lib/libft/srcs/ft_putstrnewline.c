#include "libft.h"

void	ft_putstrnewline(const char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
