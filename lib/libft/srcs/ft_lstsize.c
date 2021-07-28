#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*ptr;

	if (lst == NULL)
		return (0);
	counter = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		++counter;
		ptr = ptr->next;
	}
	return (counter);
}
