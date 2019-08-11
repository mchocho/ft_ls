#include "ft_ls.h"

void ft_initlist(LinkedList *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}
