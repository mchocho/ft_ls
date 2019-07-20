#include "./ft_ls.c"

int	ft_isdir(struct stat fstat)
{
	return (S_ISDIR(fstat.st_mode));
}


static void ft_printpermissions(char *path)
{
	struct stat fstat;
	mode_t protected;

	if (stat(path, &fstat) < 0)
		return ;

	protected = fstat.st_mode;

	ft_putchar((ft_isdir(fstat)) ? 'd' : '-');
	ft_putchar((protected & S_IRUSR) ? 'd' : '-');
	ft_putchar((protected & S_IWUSR) ? 'w' : '-');
	ft_putchar((protected & S_IXUSR) ? 'x' : '-');
	ft_putchar((protected & S_IRGRP) ? 'd' : '-');
	ft_putchar((protected & S_IWGRP) ? 'w' : '-');
	ft_putchar((protected & S_IXGRP) ? 'x' : '-');
	ft_putchar((protected & S_IROTH) ? 'd' : '-');
	ft_putchar((protected & S_IWOTH) ? 'w' : '-');
	ft_putchar((protected & S_IXOTH) ? 'x' : '-');
	return ;
}
