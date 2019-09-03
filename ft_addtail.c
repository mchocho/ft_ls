#include "ft_ls.h"

void	ft_addtail(LinkedList *list, char *filename, time_t lm, time_t acc)
{
	s_file *entry;
	
	entry = (s_file*)malloc(sizeof(s_file));
	entry->filename = filename;
	entry->lastmodified = ft_contructctimeobj(lm);
	entry->accesstime = ft_contructctimeobj(acc);
	entry->next = NULL;
	if (list->head == NULL)
		list->head = entry;
	else
		list->tail->next = entry;
	list->tail = entry;
}
