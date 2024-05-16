/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:37:47 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/16 10:53:58 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int  same_varibale(char **envp, char *var)
{
    int i;
    
    i = 0;
    while (envp[i] != NULL)
    {
        if (is_same(envp[i], var) == true)
            return (i);
        i++;
    }
    return (-1);
}