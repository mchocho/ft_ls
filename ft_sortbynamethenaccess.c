#include "ft_ls.h"

static int	ft_timecmp(t_file *current, t_file *next)
{
	if (current->accesstime == next->accesstime)
		return (ft_nsecondscmp(current->filename, next->filename, 0));
	return (current->accesstime < next->accesstime);
}

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
		if (ft_timecmp(current, next))//current->accesstime < next->accesstime)
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
