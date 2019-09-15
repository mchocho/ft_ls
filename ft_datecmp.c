#include "ft_ls.h"

static int	ft_monthcmp(ctimeobject *t1, ctimeobject *t2)
{
	char list[30];
	int test1;
	int test2;

	list = "Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec";
	test1 = ft_stristr(list, t1->month);
	test2 = ft_stristr(list, t2->month);

	if (test1 == -1 || test2 == -1)
		return (t1->epoch < t2->epoch);
	return (test1 < test2);
}

static int	ft_daycmp(ctimobject *t1, ctimeobect *t2)
{
	char list[30];
	int test1;
	int test2;

	list = "Mon Tue Wed Thu Fri Sat Sun";
	test1 = ft_stristr(list, t1->day);
	test2 = ft_stristr(list, t2->day);

	if (test1 == -1 || test2 == -1)
		return (t1->epoch < t2->epoch);
	return (test1 < test2);
}

static int	ft_castandcmp(char *val1, char *val2)
{
	return (ft_atoi(val1) < ft_atoi(val2));
}

int		ft_datecmp(time_t time1, time_t time2)
{
	ctimeobject *ctobject1;
	ctimeobject *ctobject2;
	int result;

	result = time1 < time2;

	if (!(ctobject1 = ft_constructctimeobject(time1)))
		return (result);
	else if (!(ctobject2 = ft_constructctimeobject(time2)))
	{
		ft_cleanctimeobject(&ctobject1);
		return (result);
	}
	else if (ft_strcmp(ctobject1->ctime, ctobject2->ctime) != 0)
	{
		if (ft_strcmp(ctobject1->year, ctobject2->year) != 0)
			result = ft_castandcmp(ctobject1->year, ctobject2->year);
		else if (ft_strcmp(ctobject1->month, ctobject2->month) != 0)
			result = (ft_monthcmp(ctobject1, ctobject2));
		else if (ft_strcmp(ctobject1->day, ctobject2->day) != 0)
			result = (ft_daycmp(ctobject1, ctobject2));
		else if (ft_strcmp(ctobject1->hours, ctobject2->hours) != 0)
			result = ft_castandcmp(ctobject1->year, ctobject2->year);
		else if (ft_strcmp(ctobject2->mins, ctobject2->mins) != 0)
			result = ft_castandcmp(ctobject1->mins, ctobject2->mins);
		else if (ft_strcmp(ctobject1->sec, ctobject2->sec))
			result = ft_castandcmp(ctobject1->sec, ctobject2->sec);
	}
	ft_cleanctimeobject(&ctobject1);
	ft_cleanctimeobject(&ctobject2);
	return (result);

}
