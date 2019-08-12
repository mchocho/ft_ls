#include "ft_ls.h"

struct ctimeobject ft_constructctimeobj(const time_t value)
{
	char			*tv;
	char			**split;
	char			**time;
	struct ctimeobject	*ctimeobj;
	
	tv = ctime(value);
	split = ft_strsplit(tv, ' ');
	time = ft_strsplit(split[3], ':');
	ctimeobj = (ctimeobject *)malloc(sizeof(timeobject));

	ctimeobj->day = split[0];
	ctimeobj->month = split[1];
	ctimeobj->date = split[2];
	ctimeobj->hours = time[0];
	ctimeobj->minutes = time[1];
	ctimeobj->seconds = time[2];
	ft_strncpy(&ctimeobj->year, split[4], 4);
	ctimeobj->ctime = tv;
	ctimeobj->epoch = value;

	return (ctimeobj);
}
