/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:18:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/01 10:49:05 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_echo(char **av, bool is_line)
{
    int i;

    i = 0;
    while (av[i] != NULL)
    {
        printf("%s", av[i]);
        if (av[i + 1] != NULL)
            printf(" ");
        i++;
    }
    if (is_line == true)
        printf("\n");
}