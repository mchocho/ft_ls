#include "ft_ls.h"

void	ft_sortbynamethenaccess(LinkedList *list)
{
	t_file *current;
	t_file *next;

	ft_sortbyascii(list);
	current = list->head;

	while (current != NULL)
	{
		next = current->next;
		if (ft_strcmp(current->filename, next->filename) == 0)
		{
			if (current->accesstime->epoch < next->accesstime->epoch)
			{
				current->next = next->next;
				next->next = current;
				if (ft_structcmp(next, list->head))
					list->head = current;
				if (ft_structcmp(current, list ->tail))
					list->tail = next;
				current = list->head;
				continue;
			}
			current = next;
		}
	}
	return ;
}
