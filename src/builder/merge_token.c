#include "minishell.h"

void    merge_token(t_token **lst)
{
    t_token *cur;

    cur = *lst;
    while(cur != NULL)
    {
        if(cur && (cur->endToken == FLAG_ON)){
            // printf("Not need to merge :" BLU  "%s\n" RESET, cur->value);
        }
        else if(cur && (cur->endToken == FLAG_OFF)){
            // printf("Need to merge     :" RED "%s\n" RESET, cur->value);            
        }
        cur = cur->next;
    }
}

void    delete_token(t_token **lst, int tokToDel_id)
{
    t_token *cur;
    
    cur = *lst;
    while(cur->token_id != tokToDel_id)
        cur = cur->next;
    if(cur && cur->next != NULL)
    {   
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    else
        cur->prev->next = NULL;
    free(cur->value);
    free(cur);
}

void    combineTokValue(t_token **lst)
{
    t_token *cur;
    char *tmp;

    cur = *lst;
    while(cur != NULL)
    {
        if(cur && (cur->endToken == FLAG_ON && cur->to_merge == FLAG_OFF))
            cur = cur->next;
        if(cur && (cur->endToken == FLAG_OFF && cur->to_merge == FLAG_ON) && cur->next->type != pipe_)
        {
            tmp = ft_strdup(cur->value);
            free(cur->value);
            cur->value = ft_strjoin(tmp, cur->next->value);
            free(tmp);
            // printf("NEW CUR VALUE OF  :" RED "%d " RESET "is " BLU "%s\n" RESET, cur->token_id, cur->value);
            cur->endToken = cur->next->endToken;
            cur->to_merge = cur->next->to_merge;
            delete_token(lst, cur->next->token_id);
            add_garbage(cur->value);
        }
		else if(cur)
			cur = cur->next;
    }
}


