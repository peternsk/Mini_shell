#include "minishell.h"

// void    ft_env(t_cmd *env)
// {
//     int i;

//     i = 0;
//     if (env)
//     {
//         if (env->envp)
//         {
//             while (env->envp[i] != NULL)
//             {
//                 printf("%s\n", env->envp[i]);
//                 i++;
//             }
//         }
//     }
// }

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