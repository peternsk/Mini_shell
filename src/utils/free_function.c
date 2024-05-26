

#include "minishell.h"

void free_list(t_token **list)
{
    t_token *tmp;
    
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