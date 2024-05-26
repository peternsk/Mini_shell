#include "minishell.h"

void    setDelimiter(t_token **lst)
{
    t_token *cur;
    
    cur = *lst;
    while(cur != NULL)
    {
        if(cur->type == here_doc && cur->next != NULL)
        {
            cur = cur->next;
            if(cur->type == argument)
                cur->type = delimter;
        }
        cur = cur->next;
    }
}

void    setFile(t_token **lst)
{
    t_token *cur;
    
    cur = *lst;
    while(cur != NULL)
    {
        if((cur->type == here_doc || cur->type == apnd_op_redir || cur->type == out_p_redir || cur->type == in_p_redir) && cur->next != NULL)
        {
            cur = cur->next;
            if(cur->type == argument)
                cur->type = _file;
        }
        cur = cur->next;
    }
}