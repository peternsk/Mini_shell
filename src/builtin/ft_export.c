#include "minishell.h"

// void ft_export(t_cmd * built, char **envp, char **vars, bool print)
// {
    // char **tmp;

    // tmp = NULL;
    // if (print)
        // printEnvp(envp);
    // else
    // {
        // tmp = check_duplicate(vars);
        // for (int i = 0; tmp[i] != NULL; i++)
        //     printf("----%s\n", tmp[i]);
        // built->envp = addEnvp(envp, tmp);
        // built->envp = addEnvp(envp, tmp);
    // }
    // (void)print;
    // (void)vars;
    // (void)envp;
    // (void)built;
    // int i = 0;
    // if (envp)
    // {
    //     while (envp[i] != NULL)
    //     {
    //         printf("%s\n", envp[i]);
    //         i++;
    //     }
    // }
    // printf("==========================================\n");
    // for (int i = 0; envp[i] != NULL; i++)
    //     printf("%s\n", envp[i]);
// }

void print_env_check(t_env *node)
{
    t_env *current;
    current = node;
    while (current != NULL)
    {
        printf("-=====================\n current->key %s \n current-> value %s \n ================\n", current->key, current->value);
        current = current->next;
    }
}

void ft_export(t_cmd * built, char **vars, bool print)
{
    t_env   *new_envp;
    char    **n_vars;

    new_envp = built->glob->envVarlst;
    n_vars = check_duplicate(vars);
    if (print == true)
        printEnvp(built->envp);
    else
        is_add_envp(built->glob->envVarlst, built);
    // print_env_check(built->glob->envVarlst);
}