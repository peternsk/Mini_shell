

#include "minishell.h"

bool    delim_cmp(char *input, char *delimiter)
{
    int i;

    i = 0;
    if(ft_strlen(input) != ft_strlen(delimiter))
        return(false);
    while(input[i] != '\0')
    {
        if(input[i] == delimiter[i])
            i++;
        else
            return(false);
    }
    return(true);
}