#include "minishell.h"

char  **free_array(char **vars)
{
    int i = 0;
    while (vars[i] != NULL)
    {
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
        is_add_envp(built->glob->envVarlst, built->av_cmd);
}