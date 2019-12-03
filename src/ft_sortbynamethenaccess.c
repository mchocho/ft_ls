#include "../includes/ft_ls.h"

int	ft_nsecondscmp(t_file *current, t_file *next)
{
	return (current->file_status->st_atim.tv_nsec < next->file_status->st_atim.tv_nsec);
}


static int	ft_timecmp(t_file *current, t_file *next)
{
	if (current->file_status->st_atime == next->file_status->st_atime)
		return (ft_nsecondscmp(current, next));
	return (current->file_status->st_atime < next->file_status->st_atime);
}

void	ft_sortbynamethenaccess(LinkedList *list)
{
	//t_file *current;
	t_file *next;
	t_file *previous;

	if (list == NULL)
		return ;

	ft_sortbyascii(list);
	list->current = list->head;

	while (list->current != NULL && list->current->next != NULL)
	{
		next = list->current->next;
		if (ft_timecmp(list->current, next))
		{
			list->current->next = next->next;
			next->next = list->current;
			if (previous != NULL)
				previous->next = next;
			if (ft_structcmp(next, list->head))
				list->head = list->current;
			if (ft_structcmp(list->current, list->tail))
				list->tail = next;
			list->current = list->head;
			previous = NULL;
			continue;
		}
		previous = list->current;
		list->current = next;
	}
	return ;
}
