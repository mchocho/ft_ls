
#include "ft_ls.h"

void ft_initflagobject(flagobject *flagship)
{
        flagship->l_flag = false;
        flagship->r_flag = false;
        flagship->R_flag = false;
        flagship->t_flag = false;
        flagship->a_flag = false;
        flagship->u_flag = false;
        flagship->f_flag = false;
        flagship->g_flag = false;
        flagship->d_flag = false;
        flagship->fod_exclusively = false;
        flagship->isvalid = true;
        flagship->terminate_ls = false;
}
