#include "minishell.h"

void    run_all_here(t_cmd **lst)
{
    t_cmd *tmp;

    tmp = *lst;
    while(tmp)
    {
        run_here_redlst(tmp);
        tmp = tmp->next;
    }
}