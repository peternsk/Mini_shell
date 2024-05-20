#include "minishell.h"

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
char  **free_array(char **vars)
{
    int i = 0;
    while (vars[i] != NULL)
    {
        // printf("%s\n", vars[i]);
        free(vars[i]);
             i++;
    }
    vars = NULL;
    return (vars);
}
void ft_export(t_cmd * built,  bool print)
{
    if (print == true)
        printEnvp(built->envp);
    else
    {
        is_add_envp(built->glob->envVarlst, built->av_cmd);
        // list_to_tab(&built->glob->envVarlst);
        // print_env_check((built->glob->envVarlst));
    }
}