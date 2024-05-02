#include "minishell.h"

char *is_same_key_value(char **envp, char *s, int index)
{
    char *new_str;

    new_str = NULL;
    if (index == -1)
        return (s);
    if (ft_strncmp((const char *)envp[index], (const char *)s, ft_strlen((const char *)envp[index])) == 0)
        return (new_str);
    else
        new_str = ft_strdup(s);
    return (new_str);
}