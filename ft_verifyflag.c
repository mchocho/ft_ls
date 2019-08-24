#include "ft_ls.h"

void ft_errormessage_0(char c)
{
	ft_putstr("ls: unknown option ");
	ft_putstr("-- ");
	ft_putchar(c);
	ft_putchar('\n');
}

void ft_initflagobject(flagobject *flagship)
{
	flagship->l_flag = false;
	flagship->r_flag = false;
	flagship->R_flag = false;
	flagship->t_flag = false;
	flagship->a_flag = false;
	flagship->fod_exclusively = false;
	flagship->isvalid = true;
	flagship->terminate_ls = false;
}


flagobject *ft_verifyflag(char *flag)
{
	flagobject	*flagship;
	int		len;
	int		dashcount;
	int		i;

	if(!(flagship = (flagobject *)malloc(sizeof(flagobject))))
		return (NULL);
	len = ft_strlen(flag);
	dashcount = 0;
	i = 0;
	ft_initflagobject(flagship);

	if (len < 2 || flag[0] != '-')
	{
		flagship->isvalid = false;
		return (flagship);
	}
	else if (ft_stristr(flag, "--") == 0)
	{
		if (len == 2)
		{
			flagship->fod_exclusively = true;
			return (flagship);
		}
		else if (ft_isvalidoption(flag[3]) && len == 3)
		{
			if (flag[3] == '[')
				return (ft_handlebrackets(ft_strchr('['), flagship));
			else if (flag[3] == 'g')
				flagship->terminate_ls = true;
			else
			{
				ft_errormessage_0();
			}
		}
		else if ()
	}
}
