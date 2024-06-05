

#include "minishell.h"

void    ft_removeQuotes(t_token **tkLst)
{
    t_token *last;
    
    last = *tkLst;
    while(last != NULL)
    {
        if(last->type == SQA)
        {
            last->value = ft_strtrim(last->value, "\'");
            add_garbage(last->value);
        }
        if(last->type == DQA)
        {
            last->value = ft_strtrim(last->value, "\"");
            add_garbage(last->value);   
        }
        last = last->next;
    }
}