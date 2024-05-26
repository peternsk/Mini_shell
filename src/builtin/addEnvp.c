#include "minishell.h"

int is_there_key_or_value(char *var)
{
    char *look;

    look = ft_strchr(var, '=');
    if (look)
    {
        look++;
        if (ft_strlen(look) > 0)
            return (2);
    }
    return (1);
}
char    *copy_key(char *str)
{
    int     i;
    char    *new;

    i = 0;
    new = NULL;
    if (str)
    {
        while (str[i] != '\0' && str[i] == '=')
            i++;
        new = malloc(sizeof(char *)  * (i + 1) );
        if (!new)
            return (NULL);
        i = 0;
        while (str[i] != '\0' && str[i] != '=')
        {
            new[i] = str[i];
            i++;
        }
        new[i] = '\0';
    }
    return (new);
}


void    put_key_value(t_env *env, bool both, char *vars)
{
    if (both)
    {
        // printf("------------------ is two\n");
        env->key = copy_key(vars);
        env->value = copy_value(vars);
    }
    else
    {
        // printf("------------------ is one");
        env->key = copy_key(vars);
        env->value = NULL;
    }
    // printf(" function(addEnvp): -- key %s\n -- value %s -- bool %d \n", env->key, env->value, both);
}
t_env   *addEnvp(char *vars)
{
    t_env *new;

    new = NULL;
    if (vars)
    {
        new = malloc(sizeof(t_env));
        // if (ft_strchr(vars, '='))
            // new->flag = 1;
        if (new)
        {
            if (is_there_key_or_value(vars) == 1)
                put_key_value(new, false, vars);
            if (is_there_key_or_value(vars) == 2)
                put_key_value(new, true, vars);
            new->next = NULL;
        }
    }
    return (new);
}