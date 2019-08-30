/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:23:05 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/30 14:05:48 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printlist(LinkedList *list, flagobject *flagship)
{
	t_file *current;

	if (!flagship->isvalid || flagship->terminate_ls)
		return ;
	current = list->head;
	while (current != NULL)
	{
		if (flagship->l_flag || flagship->g_flag)
			ft_longlist(current->filename, flagship);
		else
		{
			if (i != 0)
				ft_putchar('\t');
			ft_putstr(ft_splicpath(current->filename));
		}
		current = current->next;
	}
	if (!flagship->l_flag && !flagship->g_flag)
		ft_putchar('\n');
	return ;
}
