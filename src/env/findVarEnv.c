/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findVarEnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:54 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/08 00:08:31 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool    char_search(char *tok_value, char c)
{
    int i;

    i = 0;
    while(tok_value[i])
    {
        if(tok_value[i] == c)
            return(true);
        i++;
    }
    return(false);
}

char    *find_tmp_key(char *value)
{
    int     i;
    int     start;
    char    *tmpKey;

    i = 0;
    start = i;
    tmpKey = NULL;
    while(value[i] && (value[i] != '$' || is_space(value[i]) == false))
        i++;
    if(i > start)
    {
        tmpKey = (char *)malloc((sizeof(char) * (i - start)) + 1);
        ft_strncpy(tmpKey, value, (i - start));
    }
    return(tmpKey);
}

char    *find_key_in_list(t_env **lst, char *tmpKey, char *tmpvalue)
{
    t_env *current;

    current = *lst;
    while(current != NULL)
    {
        if(ft_strcmp(tmpKey, current) == true)
        {
            tmpvalue = ft_strdup(current->value);
            return(tmpvalue);
        }
        current = current->next;
    }
    return(0);
}