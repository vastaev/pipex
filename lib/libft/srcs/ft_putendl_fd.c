//part2
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	step;

	step = 0;
	if (s)
	{
		while (s[step])
		{
			write(fd, &s[step], 1);
			step++;
		}
	}
	write(fd, "\n", 1);
}
