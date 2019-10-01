#include "ft_ls.h"

char	*ft_parseurl(char *path)
{
	if (!*path)
		return (path);
	if (ft_stristr(path, "./") != 0)
		path = ft_strcat("./", path);
	if (path[ft_strlen(path) - 1] != '/')
		return (ft_strcat(path, "/"));
	return (path);

}
