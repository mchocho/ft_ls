#include "ft_ls.h"

ctimeobject *ft_constructctimeobj(time_t value)
{
	char			*ts;
	char			**seg;
	char			**time;
	ctimeobject		*ctimeobj;

	ts = ctime(&value);
	seg = ft_strsplit(ts, ' ');
	time = ft_strsplit(seg[3], ':');
	if (!(ctimeobj = (ctimeobject *)malloc(sizeof(ctimeobject))))
		return (NULL);

	ctimeobj->day = seg[0];
	ctimeobj->month = seg[1];
	ctimeobj->date = seg[2];
	ctimeobj->hours = time[0];
	ctimeobj->min = time[1];
	ctimeobj->sec = time[2];
	ctimeobj->year = ft_strndup(seg[4], 4);
	ctimeobj->ctime = ts;
	ctimeobj->epoch = value;

	return (ctimeobj);
}
