#include "minishell.h"

void    ft_env(t_cmd *env)
{
    t_env *curr;
    if(!env->glob->envVarlst)
        return;

    curr = env->glob->envVarlst;
    while(curr  && curr->eql_sign == true)
    {
        printf("%s=%s\n", curr->key,curr->value);
        curr = curr->next;
    }
}