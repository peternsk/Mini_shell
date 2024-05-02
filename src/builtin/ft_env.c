#include "minishell.h"

void    ft_env(t_cmd *env)
{
    int i;

    i = 0;
    if (env)
    {
        if (env->envp)
        {
            while (env->envp[i] != NULL)
            {
                printf("%s\n", env->envp[i]);
                i++;
            }
        }
    }
}