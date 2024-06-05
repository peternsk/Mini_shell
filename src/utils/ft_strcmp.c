

#include "minishell.h"

bool    ft_strcmp(char *tmp_key, char *envKey)
{
    int i;
    char *newKey;
    i = 0;
    newKey = ft_strtrim(tmp_key, "\"");
    add_garbage(newKey);
    if(ft_strlen(newKey) != ft_strlen(envKey))
        return(false);
    while(newKey[i] != '\0')
    {
        if(newKey[i] == envKey[i])
            i++;
        else
            return(false);
    }
    return(true);
}