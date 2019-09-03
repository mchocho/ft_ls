#include "ft_ls.h"

void	ft_reverselist(LinkedList *list)
{
	t_file *current, *next, *prev;
	
	current = list->head;
	next = NULL;
	prev = NULL;
	list->tail = current;
	while(current != NULL)
	{
		//Store next
		next = current->next;
		//Reverse current pointer
		current->next = prev;
		//Move pointer one position
		prev = current;
		current = next;
	}
	list->head = prev;
	return ;
}
