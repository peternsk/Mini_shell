#include "minishell.h"


void    free_list_garb(t_garbage **list)
{
    t_garbage *tmp;
    
    if (list)
    {
        while (*list != NULL)
        {
            tmp = (*list)->next;
            free(*list);
            (*list) = tmp;
        }
        *list = NULL;
    }
}