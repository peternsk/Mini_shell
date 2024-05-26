#include "minishell.h"

void    change_key_value(t_env **env, char *vars)
{
    char    *var_parsing;

    var_parsing = NULL;
    if (env && vars)
    {
        // printf(" .. change value ..\n");
        var_parsing = ft_strchr(vars, '=');
        if (var_parsing)
        {   var_parsing++;
            if (ft_strcmp((*env)->value, var_parsing) == false)
            {
                free((*env)->value);
                (*env)->value = NULL;
                (*env)->value = copy_value(vars);
                (*env)->eql_sign = true;
            }
            // env->flags
            // printf(" \\\\\the value as be change \n funtion(is_add_envp): add in node \n key -- %s \n value -- %s \\\\\n",(*env)->key, (*env)->value);
        }
    }
}

void    where_to_envp(t_env **env, char *vars, int index)
{
    t_env *node;
    t_env *new_node;
    int     i;

    node = *env;
    new_node = NULL;
    i = 0;
    if (vars)
        // printf("[%d index] [%s]\n",index, vars);
    if (index >  0)
    {
        while (node != NULL)
        {
            if (i == index)
            {
                // printf("is chnage value .....\n");
                change_key_value(&node, vars);
                break;
            }
            i++;
            node = node->next;
        }
    }
    if (index == -1)
        add_var_to_end(env, intEnvVar(new_node, vars));
    // if (node)
        // printf("function(is_add_envp): =============\n add in node \n key -- %s \n value -- %s \n================\n", node->key,node->value);
}


char    *copy_key_pars(char *str)
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
int len_env(t_env *env)
{
    int i ;

    i = 0;
    if (env)
    {
        while (env != NULL)
        {
            i++;
            env = env->next;
        }
    }
    return (printf("----------------------------------------------------------------------------------------------------------------%d\n" , i), i);
}
void    is_add_envp(t_env *old_envp, char **arg)
{
    t_env   *node;
    char    **vars;
    int     add;
    int     i;

    i = 0;
    node = old_envp;
    vars = check_duplicate(arg);
    while (vars[i] != NULL)
    {
        add = is_same_key(node, copy_key_pars(vars[i]));
        if (is_key(vars[i]) == true)
        {
            is_same_key_value(node, vars[i], add); 
            where_to_envp(&old_envp, vars[i], add);
        }
        else
             where_to_envp(&old_envp, vars[i], add);
        i++;
    }
}