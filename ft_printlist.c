/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:23:05 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/07 12:50:27 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlist(LinkedList *list, flagobject *flagship)
{
	t_file *current;
	int		i;

	if (!flagship->isvalid || flagship->terminate_ls)
		return ;
	current = list->head;
	i = 0;
	while (current != NULL)
	{
		if (flagship->l_flag || flagship->g_flag)
			ft_longlist(current->filename, flagship);
		else
		{
			if (i != 0)
				ft_putchar('\n');
			ft_putstr(ft_splicepath(current->filename));
			//ft_putstr(current->filename);
		}
		current = current->next;
		i++;
	}
	if (!flagship->l_flag && !flagship->g_flag)
		ft_putchar('\n');
	return ;
}

/*int main(int argc, char **argv)
{
	t_file *foo;

	ft_putstr("Testing ft_printlist.c\n------------------------------\n");

	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

	flagobject *flagship = (flagobject*)malloc(sizeof(flagobject));
	
	ft_initlist(list);

	ft_initflagobject(flagship);

	flagship->l_flag = true;
	flagship->R_flag = true;

	time_t epoch = 0;

	foo = (t_file *)malloc(sizeof(t_file));

	if (argc > 1)
		foo->filename = argv[1];
	else
		foo->filename = "../";
	
	foo->lastmodified = ft_constructctimeobj(epoch);
	foo->accesstime = ft_constructctimeobj(epoch);
	foo->next = NULL;

	list->head = foo;
	list->tail = foo;

	ft_putstr("Introducing ft_printlist()\n");
	ft_printlist(list, flagship);
	
	return 0;
}*/
