#include "ft_ls.h"

static int	ft_monthcmp(ctimeobject *t1, ctimeobject *t2)
{
	char *list;
	int test1;
	int test2;

	list = ft_strdup("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec");
	test1 = ft_stristr(list, t1->month);
	test2 = ft_stristr(list, t2->month);
	ft_strclean(&list);

	if (test1 == -1 || test2 == -1)
		return (t1->epoch < t2->epoch);
	return (test1 < test2);
}

static int	ft_daycmp(ctimeobject *t1, ctimeobject *t2)
{
	char *list;
	int test1;
	int test2;

	list = ft_strdup("Mon Tue Wed Thu Fri Sat Sun");
	test1 = ft_stristr(list, t1->day);
	test2 = ft_stristr(list, t2->day);
	ft_strclean(&list);

	if (test1 == -1 || test2 == -1)
		return (t1->epoch < t2->epoch);
	return (test1 < test2);
}

static int	ft_castandcmp(char *val1, char *val2)
{
	int n1;
	int n2;

	n1 = (val1[0] != 0) ? ft_atoi(val1) : ft_atoi(val1 + 1);
	n2 = (val2[0] != 0) ? ft_atoi(val2) : ft_atoi(val2 + 1);
	return (n1 < n2);
}

int		ft_datecmp(time_t time1, time_t time2)
{
	ctimeobject *ctobject1;
	ctimeobject *ctobject2;
	int result;

	result = time1 < time2;

	if (!(ctobject1 = ft_constructctimeobj(time1)))
	{	
		ft_putstr("ft_constructctimeobj() failed to run\n");
		return (result);
	}
	else if (!(ctobject2 = ft_constructctimeobj(time2)))
	{
		ft_putstr("ft_constructctimeobj() failed to run\n");
		//ft_cleanctimeobject(ctobject1);
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
		else if (ft_strcmp(ctobject2->min, ctobject2->min) != 0)
			result = ft_castandcmp(ctobject1->min, ctobject2->min);
		else if (ft_strcmp(ctobject1->sec, ctobject2->sec) != 0)
		{
			ft_putstr("The seconds differ!\n");
			result = ft_castandcmp(ctobject1->sec, ctobject2->sec);
		}
	}
	//ft_cleanctimeobject(ctobject1);
	//ft_cleanctimeobject(ctobject2);
	return (result);

}
