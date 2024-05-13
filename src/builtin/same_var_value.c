#include "minishell.h"

char *ft_cpyvar(char *s)
{
    int i;
    char *c;

    i = 0;
    while (s[i] != '=' && s[i] == '\0')
        i++;
    c = malloc(sizeof(char *) * (i + 1));
    if (!c)
        return (NULL);
    i = 0;
    while (s[i] != '=' && s[i] != '\0')
    {
        c[i] = s[i];
        i++;
    }
    c[i] = '\0';
    return (c);
}

int index_vars_is(char **envp, char *var)
{
    int i;
    
    i = 0;
    while (envp[i] != NULL)
    {
        if (is_same(envp[i], var) == true)
            return (i);
        i++;
    }
    return (-1);
}

int same_var_value(char **envp, char *var)
{
    int index;

    index = index_vars_is(envp, ft_cpyvar(var));
    if (index == -1)
        return (index);
    return (index);
}