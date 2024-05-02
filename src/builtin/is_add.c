#include "minishell.h"

int is_add(char **envp, char *var, int kv)
{
    int i;

    i = 0;

    if (kv == 1)
    {
        if (same_varibale(envp, var) == 1)
        {
            return (1);
        }
    }
    else
    {
        if (same_var_value(envp, var) == 1)
            return (2);
    }
    return (0);
}