#include "minishell.h"

char    *copy_value(char *str)
{
    size_t     i;
    int     j;
    char    *new;

    i = 0;
    j = 0;
    new = NULL;
    if (str)
    {
        while (str[i] != '\0' && str[i] != '=')
            i++;
        if (str[i])
            i++;
        new = malloc(sizeof(char *)  * (ft_strlen(str) + 1));
        if (!new)
            return (NULL);
        while (str[i] != '\0')
        {
            new[j] = str[i];
            i++;
            j++;
        }
        new[j] = '\0';
    }
    return (new);
}