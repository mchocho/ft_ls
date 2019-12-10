#include "../includes/ft_ls.h"

void	ft_reverselist(LinkedList *list)
{
	t_file *current, *next, *prev;
	
	current = list->head;
	next = NULL;
	prev = NULL;
	list->tail = current;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;
	return ;
}
