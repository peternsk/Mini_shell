/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:21:08 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/07 23:59:16 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool    ft_strcmp(char *tmpKey, char *envKey)
{
    int i;

    i = 0;
    if(ft_strlen(tmpKey != ft_strlen(envKey)))
        return(false);
    while(tmpKey[i] != '\0')
    {
        if(tmpKey[i] == envKey[i])
            i++;
        else
            return(false);
    }
    return(true);
}