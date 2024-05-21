#include "minishell.h"

t_env *free_node(t_env *env)
{
    if (env)
    {
        free(env->key);
        free(env->value);
        free(env);
    }
    return (NULL);
}
void    remove_from_env(t_env *node, int remove)
{
    int     index;
    t_env   *current;
    t_env   *n_node;

    index = 0;
    current = node;
    n_node = NULL;
    while (current != NULL && index != remove)
    {
        index++;
        n_node = current;
        current = current->next;
    }
    if (current == NULL)
        return ;
    n_node->next = current->next;
    current = free_node(current);
}

void    index_search_env(char **env, int index)
{
    int i;

    i = 0;
    while (env[i] != NULL)
    {
        if (i == index)
        {
            printf(":::::::::::::::::::::::::::[%s]\n", env[i]);
            return ;
        }
        i++;
    }
}
// void ft_unset(t_cmd *unset)
// {
//     char **av;
//     int index;
//     int i;

//     i = 0;
//     av = NULL;
//     index = -1;
//     if (size(unset->av_cmd) > 1)
//     {
//         // av = check_duplxicate(unset->av_cmd);
//         if (!av)
//             return ;
//         while (av[i] != NULL)
//         {
//             if (ft_strchr(av[i], '=') != NULL)
//             {
//                 // index = same_var_value(unset->envp, av[i]);
//                 av[i] = is_same_key_value(unset->envp, av[i], index);
//                 index_search_env(unset->envp, index);
//                 remove_from_env(unset->envp, index);
//                 printf("atfer search :: ");
//                 index_search_env(unset->envp, index);
//             }
//             else 
//             {
//                 //  index = same_varibale(unset->envp, av[i]);
//                  index_search_env(unset->envp, index);
//                  remove_from_env(unset->envp, index);
//                     printf("atfer search :: ");
//                  index_search_env(unset->envp, index);
//             }
//             i++;
//         }
//     }
// }

char    *copy_key_pars_unset(char *str)
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

void ft_unset(t_cmd *unset)
{
    t_env   *linked_node;
    int     i;
    int     remove;

    linked_node = unset->glob->envVarlst;
    i = 1;
    remove = 0;
    while (unset->av_cmd[i] != NULL)
    {

        remove = is_same_key(linked_node, copy_key_pars_unset(unset->av_cmd[i]));
        if (remove > -1)
        {
            remove_from_env(linked_node, remove);
            return ;
        }

        linked_node = linked_node->next;
    }
}