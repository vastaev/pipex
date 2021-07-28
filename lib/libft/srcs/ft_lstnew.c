//bonus
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelem;

	newelem = (t_list *)malloc(sizeof(t_list));
	if (newelem == 0)
		return (0);
	newelem->content = content;
	newelem->next = NULL;
	return (newelem);
}
