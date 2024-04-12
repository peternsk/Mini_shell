/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:32:42 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/12 10:04:34 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_combine(char *s1, char *s2)
{
    int i;
    int j;
    char *combStr;
    
    i = -1;
    j = -1;
    combStr = (char *)malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2)) + 1);
	if(!combStr)
		return(0);
    while(s1[++i])
        combStr[i] = s1[i];
    while(s2[++j])
    {
        combStr[i] = s2[j];
        i++;
    }
    combStr[i] = '\0';
    return(combStr);
}
