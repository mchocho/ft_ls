#include "ft_ls.h"

void	ft_sortbynamethenaccess(LinkedList *list)
{
	t_file *current;
	t_file *next;
	t_file *previous;

	ft_sortbyascii(list);
	current = list->head;

	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		if (current->accesstime < next->accesstime)
		{
			current->next = next->next;
			next->next = current;
			if (previous != NULL)
				previous->next = next;
			if (ft_structcmp(next, list->head))
				list->head = current;
			if (ft_structcmp(current, list ->tail))
				list->tail = next;
			current = list->head;
			previous = NULL;
			continue;
		}
		previous = current;
		current = next;
	}
	return ;
}
