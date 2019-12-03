#include "../includes/ft_ls.h"

char *ft_strippath(char *path)
{
	char	temp[1024];
	int	toggle;

	ft_bzero(temp, 1);
	toggle = false;
	if (*path == '\0')
		return (*path);
	if (ft_stristr(path, "./") == '0')
	{
		ft_strcpy(temp, path + 2);
		toggle = true;
	}

	if (while())
}
