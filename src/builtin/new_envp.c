/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:29:24 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/25 13:31:20 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **init_tmp(char **envp, char **new, char *vars)
{
    char **tmp;

    tmp = malloc(sizeof(char *) * (size(envp) + size(new) + ft_strlen(vars) + 1));
    if (!tmp)
        return (NULL);
    return (tmp);
}
char    **cpy_vars(char **new, char *vars, int index)
{   
    int i;
    char **tmp;

    i = 0;
    tmp = malloc(sizeof(char *) * (size(new) + ft_strlen((const char *)vars) + 1));
    if (!tmp)
        return (NULL);
    while (new[i] != NULL)
    {
        if (index == i && vars != NULL)
            tmp[i] = vars;
        else
            tmp[i] = new[i];
        i++;
    }
    if (index ==  -1 && vars != NULL)
    {
        tmp[i] = vars;
        i++;
    }
    tmp[i] = NULL;

    return (tmp);
}
char **new_envp(char **envp, char **new, char *vars, int index)
{
    char **tmp;
    int i;

    i = 0;
    tmp = init_tmp(envp, new, vars);
    if (!new)
    {
        // printf("new is not here \n");
        while (envp[i] != NULL)
        {
            if (index == i && vars != NULL)
                tmp[i] = vars;
            else 
                tmp[i] = envp[i];
            i++;
        }
        if (index ==  -1 && vars != NULL)
        {
            tmp[i] = vars;
            i++;
        }
        tmp[i] = NULL;
        return (tmp);
    }
    return (cpy_vars(new, vars, index));
}