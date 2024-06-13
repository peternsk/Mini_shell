#include "minishell.h"

bool	ft_extra_exit(char *vars)
{
	int	i;

	i = 0;
    if (vars)
    {
        while (vars[i] != '\0')
        {
            if (ft_isdigit(vars[i]) == 1)
                i++;
            else
                break;
        }
        if (i == ft_strlen(vars))
            return (true);
    }
	return (false);
}

bool ft_expand_exit(char **vars)
{
    int i;

    i = 1;
    if (vars)
    {
        if (ft_extra_exit(vars[i])== true)
        {
            write(2, "exit: too many arguments\n",
					ft_strlen("exit: too many arguments\n"));
            return (true);
        }
        write(2, "exit: numeric argument required\n",
                ft_strlen("exit: numeric argument required\n"));
        return (false);
    }
}