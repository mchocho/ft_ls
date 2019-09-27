#include "ft_ls.h"

char	*ft_parseurl(char *path)
{
	if (*path == '\0')
		return (path);

	if (path[ft_strlen(path) - 1] != '/')
		return (ft_strcat(path, "/"));
	return (path);

}
