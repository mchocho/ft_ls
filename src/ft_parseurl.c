#include "../includes/ft_ls.h"

char	*ft_parseurl(char *path)
{
	char temp[1024];
	char temp_2[1024];
	ft_bzero(temp, 1);
	ft_bzero(temp_2, 2);
	if (*path == '\0')
		return (path);
	/*if (ft_stristr(path, "./") != 0)
	{
		temp = ft_strjoin("./", path);
		//path = ft_strcat("./", path);
		ft_strcleandel(&path);
		path = temp;
	}		
	if (path[ft_strlen(path) - 1] != '/')
	{
		temp = ft_strjoin(path, "/");
		//ft_strclean(&path);
		path = temp;
		//return (ft_strcat(path, "/"));
	}*/
	ft_strcpy(temp, path);
	ft_strcpy(temp_2, "./");

	/*if (ft_stristr(temp, "./") != 0 || ft_stristr(temp, "../") != 0)
	{
		ft_strcat(temp_2, temp);
		ft_strcpy(temp, temp_2);
		ft_bzero(temp_2, ft_strlen(temp_2));
	}*/
	
	if (temp[ft_strlen(path) - 1] != '/')
		ft_strcat(temp, "/");
	path = ft_strdup(temp);
	return (path);
}
