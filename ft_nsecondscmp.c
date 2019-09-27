#include "ft_ls.h"

static int	ft_isrl(char *str)
{
	return (ft_strichr("rl", ft_detectfilepathtype(str)) > -1);
}

int	ft_nsecondscmp(char *fn1, char *fn2, int tv)
{
	struct stat	fstat1;
	struct stat	fstat2;

	if (!ft_isrl(fn1) || !ft_isrl(fn2))
		return (0);
	else if (lstat(fn1, &fstat1) < 0 || lstat(fn2, &fstat2) < 0)
		return (0);
	if (tv == 1)
		return (fstat1.st_mtim.tv_nsec < fstat2.st_mtim.tv_nsec);
	else
		return (fstat1.st_atim.tv_nsec < fstat2.st_atim.tv_nsec);
}
