#include "ft_ls.h"

void	ft_sortlist(LinkedList *list, flagobject *flagship)
{
	if (!flagship->isvalid || flagship->terminate_ls)
		return ;
	if (flagship->t_flag)
		ft_sortbytime(list);
	else if (flagship->f_flag == false)
		ft_sortbyascii(list);

	if (flagship->r_flag)
		ft_reverselist(list);
	return ;
}
