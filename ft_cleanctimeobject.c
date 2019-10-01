#include "ft_ls.h"

void	ft_cleanctimeobject(ctimeobject *timeobject)
{
	ft_strclean(&(*timeobject)->day);
	ft_strclean(&(*timeobject)->month);
	ft_strclean(&(*timeobject)->date);
	ft_strclean(&(*timeobject)->min);
	ft_strclean(&(*timeobject)->sec);
	ft_strclean(&(*timeobject)->year);
	ft_strclean(&(*timeobject)->ctime);
	(*timeobject)->epoch = 0;
	free(*timeobject);
}
