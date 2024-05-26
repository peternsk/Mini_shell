

#include "minishell.h"

void    ft_pwd()
{
    char    str[PATH_MAX];
    printf("%s\n", getcwd(str, PATH_MAX));
}