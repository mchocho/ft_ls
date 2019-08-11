#include "ft_ls.h"

void	ft_addtail(LinkedList *list, char *filename, ctimeobject lm)
{
	s_file *entry;
	
	entry = (s_file*)malloc(sizeof(s_file));
	entry->filename = filename;
	entry->lastmodified = lm;
	entry->next = NULL;
	if (list->head == NULL)
		list->head = entry;
	else
		list->tail->next = entry;
	list->tail = entry;
}
