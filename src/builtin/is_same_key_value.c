#include "minishell.h"

bool check_equal_dup(char *var)
{
    char *look;

    look = ft_strchr(var, '=');
    if (look)
    {
        look++;
        if (ft_strlen(look) > 0)
            return (true);
    }
    return (false);
}
char    *pars_va_value(char *vars)
{
    int     i;
    int     j;
    char    *var_pars;
    
    i = 0;
    j = 0;
    var_pars = malloc(sizeof(char *)  * (ft_strlen(vars)));
    if (!var_pars)
        return (NULL);
    while (vars[i] != '\0' && vars[i] == '=')
        i++;
    while (vars[i] != '\0' && vars[i] != '=')
    {
        var_pars[j] = vars[i];
        j++;
        i++;
    }
    var_pars[i] = '\0';
    // free(vars);
    return (var_pars);
}

int    is_same_key_value(t_env *env, char *var, int index)
{
    t_env   *node;
    char    *pars_var;
    int     i;

    i = 0;
    node = env;
    if (env && var && check_equal_dup(var) == true)
    {
        pars_var = ft_strchr(var, '=');
        pars_var++;
        while (node != NULL)
        {
            if (index == i)
            {
                if (ft_strcmp(node->value, pars_var) == false)
                    return (i);
            }
            i++;
            node =  node->next;
        }   
        return (-1);
    }
    return (-3);
}