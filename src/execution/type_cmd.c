

#include "minishell.h"

int is_builtin(char *s)
{
    if (ft_strcmp(s, "cd") == true)
        return (8);
    if (ft_strcmp(s, "echo") == true)
        return (8);
    if (ft_strcmp(s, "pwd") == true)
        return (8);
    if (ft_strcmp(s, "export") == true)
        return (8);
    if (ft_strcmp(s, "unset") == true)
        return (8);
    if (ft_strcmp(s, "env") == true)
        return (8);
    if (ft_strcmp(s, "exit") == true)
        return (8);
    return (-1);
}

int is_files(char *s)
{
    if (ft_strcmp(s, "<<") == true)
        return (here_doc);
    if (ft_strcmp(s, ">>")== true)
        return (APOR);
    if (ft_strcmp(s, ">") == true)
        return (OPR);
    if (ft_strcmp(s, "<") == true)
        return (IPR);
    return (-1);
}

int type_cmds(char *s)
{
    int _res;
    if (!s)
        return (-1);
    _res = is_builtin(s);
    if (_res > -1)
        return (_res);
    _res = is_files(s);
    if (_res > -1)
        return (_res);
    return (command);
}