void ft_addhead(LinkedList *list, char* filename, ctimeobject lm)
{
	s_file *entry;

	entry = (s_file*)malloc(sizeof(s_file));
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
