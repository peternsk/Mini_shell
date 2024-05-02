/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:28:23 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/25 13:28:29 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool is_same(char *s, char *v)
{
    int i;

    i = 0;
    while (s[i] != '\0' && s[i] != '=' && i < (int)ft_strlen(v))
    {
        if (s[i] == v[i])
        {
            // printf("%c and %c\n", s[i], v[i]);
            i++;
        }
        else 
            return (false);
    }
    // printf(" %c -- \n", s[i]);
    // printf("====================================\n");
    if (v[i] == '\0' && s[i] == '=')
        return (true);
    return (false);
}