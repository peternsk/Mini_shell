#include "minishell.h"

int  is_line (char **av)
{
   
    if (ft_strncmp(av[1], "-n", ft_strlen("-n")) == 0)
        return (true);
    return (false);
}

bool it_print(char *av, int index)
{
        if (index == 1 && ft_strncmp(av, "-n", ft_strlen("-n")) == 0)
            return (false);
        return (true);
}
void    ft_echo(t_cmd *ec)
{
    int i;

    i = 1;
    while (i < size(ec->av_cmd))
    {
        if (ec->av_cmd[i])
        {
            if (it_print(ec->av_cmd[i], i) == true)
            {
                printf("%s", ec->av_cmd[i]);
                if (ec->av_cmd[i + 1] != NULL)
                    printf(" ");
            }
        }
        i++;
    }
    if (i == 1)
        printf("\n");
    else 
    {
        if  (is_line(ec->av_cmd) == false && size(ec->av_cmd) > 2)
            printf("\n");
    }
}
