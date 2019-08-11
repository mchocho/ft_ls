void ft_addhead(LinkedList *list, char* filename, ctimeobject lm)
{
	t_file *entry;

	entry = (t_file*)malloc(sizeof(t_file));
	entry->filename = filename;
	entry->lastmodified = lm;

	if (list->head == NULL)
	{
		list->tail = entry;
		entry->next = NULL;
	} else
		entry->next = list->head;
	list->head = entry;
}
