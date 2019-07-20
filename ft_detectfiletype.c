#include "./ft_ls.h"

static int ft_detectfiletype(mode_t mode)
{
	if (S_ISDIR(mode))
		return ('d');		//Diretory
	else if (S_ISREG(mode))
		return ('r');		//Regular file
	else if (S_ISLNK(mode))
		return ('l');		//Symbolic link
	else if (S_ISFIFO(mode))
		return ('p');		//Named pipe
	else if (S_ISBLK(mode))
	       	return ('b');		//Block device	
	else if (S_ISCHR(mode))
		return ('c');		//Character device
	else
		return (0);
}
