/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:21:08 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/13 14:29:25 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool    ft_strcmp(char *tmpKey, char *envKey)
{
    int i;
    char *newKey;
    i = 0;
    newKey = ft_strtrim(tmpKey, "\"");
    if(ft_strlen(newKey) != ft_strlen(envKey))
        return(false);
    while(newKey[i] != '\0')
    {
        if(newKey[i] == envKey[i])
            i++;
        else
            return(false);
    }
    return(true);
}