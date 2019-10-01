#include "ft_ls.h"

void	ft_cleanlist(LinkedList **list)
{
	t_file *current;
	t_file *next;

	current = (*list)->head;
	while (current != NULL)
	{
		next = current->next;
		ft_strclean(&current->filename);
		current->lastmodified = 0;
		current->accesstime = 0;
		current->next = NULL;
		free(current);
		current = next;
	}
	(*list)->head = NULL;
	(*list)->tail = NULL;
	(*list)->current = NULL;
	free(*list);
}
