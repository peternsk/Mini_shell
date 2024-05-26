#include "minishell.h"

void    ft_env(t_cmd *env)
{
    if(!env->glob->envVarlst)
        return;
    while(env->glob->envVarlst && env->glob->envVarlst->eql_sign == true)
    {
        printf("%s=%s\n", env->glob->envVarlst->key, env->glob->envVarlst->value);
        env->glob->envVarlst = env->glob->envVarlst->next;
    }
}