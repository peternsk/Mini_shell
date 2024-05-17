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
            }
            // env->flags
            // printf(" \\\\\the value as be change \n funtion(is_add_envp): add in node \n key -- %s \n value -- %s \\\\\n",(*env)->key, (*env)->value);
        }
    }
}

void    where_to_envp(t_env **env, char *vars, int index)
{
    t_env *node;
    int     i;

    node = *env;
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
        add_var_to_end(env, addEnvp(vars));
    // if (node)
        // printf("function(is_add_envp): =============\n add in node \n key -- %s \n value -- %s \n================\n", node->key,node->value);
}

int only_key(char *var)
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

void    is_add_envp(t_env *old_envp, t_cmd *cmd)
{
    t_env   *node;
    int     add;
    int     i;

    i = 1;
    node = old_envp;
    while (cmd->av_cmd[i] != NULL)
    {
        
        add = is_same_key(node, copy_key_pars(cmd->av_cmd[i]));
        if (only_key(cmd->av_cmd[i]) == true)
        {
            is_same_key_value(node, cmd->av_cmd[i], add); 
            printf("check the value %d\n", add);
            where_to_envp(&old_envp, cmd->av_cmd[i], add);
        }
        else
        {
             where_to_envp(&old_envp, cmd->av_cmd[i], add);
        }
        i++;
    }
}