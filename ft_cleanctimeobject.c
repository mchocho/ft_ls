#include "ft_ls.h"

void	ft_cleanctimeobject(ctimeobject **timeobject)
{
	ft_cleandel((*timeobject)->day);
	ft_cleandel((*timeobject)->month);
	ft_cleandel((*timeobject)->date);
	ft_cleandel((*timeobject)->mins);
	ft_cleandel((*timeobject)->sec);
	ft_cleandel((*timeobject)->year);
	ft_cleandel((*timeobject)->ctime);
	(*timeobject)->epoch = NULL;
	free(*timeobject);
}
