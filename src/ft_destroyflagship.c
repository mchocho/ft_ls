#include "../includes/ft_ls.h"

void	ft_destroyflagship(flagobject **flagship)
{
 	(*flagship)->a_flag = 0;
        (*flagship)->d_flag = 0;
        (*flagship)->f_flag = 0;
        (*flagship)->g_flag = 0;
        (*flagship)->i_flag = 0;
        (*flagship)->l_flag = 0;
       	(*flagship)->R_flag = 0;
       	(*flagship)->r_flag = 0;
        (*flagship)->t_flag = 0;
        (*flagship)->u_flag = 0;
        (*flagship)->fod_exclusively = 0;
        (*flagship)->fod_fromindex = 0;
        (*flagship)->isvalid = 0;
        (*flagship)->terminate_ls = 0;
        ft_bzero((*flagship)->d_flag_value, ft_strlen((*flagship)->d_flag_value));
	free(*flagship);
	*flagship = NULL;
}
