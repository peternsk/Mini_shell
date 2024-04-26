#include "minishell.h"

void free_str_envp(char **str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
}


char **addEnvp(char **envp, char **vars)
{
    int i;
    int index;
    char **new;

    new = NULL;
    i = 0;
    while (vars[i] != NULL)
    {
        if (ft_strchr(vars[i], '=') != NULL)
        {
            index = same_var_value(envp, vars[i]);
            vars[i] = is_same_key_value(envp, vars[i], index);
            new = new_envp(envp, new, vars[i], index);
        }
        else
        {
            index = same_varibale(envp, vars[i]);
            new = new_envp(envp, new, vars[i], index);
        }
        i++;
    }
    return (new);
}
