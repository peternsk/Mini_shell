#include "minishell.h"

void    remove_from_env(char **env, int index)
{

    while (env[index] != NULL)
    {
        env[index] = env[index + 1];
        index++;
    }
}

void    index_search_env(char **env, int index)
{
    int i;

    i = 0;
    while (env[i] != NULL)
    {
        if (i == index)
        {
            printf(":::::::::::::::::::::::::::[%s]\n", env[i]);
            return ;
        }
        i++;
    }
}
void ft_unset(t_cmd *unset)
{
    char **av;
    int index;
    int i;

    i = 0;
    av = NULL;
    if (size(unset->av_cmd) > 1)
    {
        // av = check_duplxicate(unset->av_cmd);
        if (!av)
            return ;
        while (av[i] != NULL)
        {
            if (ft_strchr(av[i], '=') != NULL)
            {
                index = same_var_value(unset->envp, av[i]);
                av[i] = is_same_key_value(unset->envp, av[i], index);
                index_search_env(unset->envp, index);
                remove_from_env(unset->envp, index);
                printf("atfer search :: ");
                index_search_env(unset->envp, index);
            }
            else 
            {
                 index = same_varibale(unset->envp, av[i]);
                 index_search_env(unset->envp, index);
                 remove_from_env(unset->envp, index);
                    printf("atfer search :: ");
                 index_search_env(unset->envp, index);
            }
            i++;
        }
    }
}