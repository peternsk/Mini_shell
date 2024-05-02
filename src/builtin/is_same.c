#include "minishell.h"

bool is_same(char *s, char *v)
{
    int i;

    i = 0;
    while (s[i] != '\0' && s[i] != '=' && i < (int)ft_strlen(v))
    {
        if (s[i] == v[i])
        {
            // printf("%c and %c\n", s[i], v[i]);
            i++;
        }
        else 
            return (false);
    }
    // printf(" %c -- \n", s[i]);
    // printf("====================================\n");
    if (v[i] == '\0' && s[i] == '=')
        return (true);
    return (false);
}