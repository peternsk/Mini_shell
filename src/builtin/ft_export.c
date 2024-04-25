/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:18:05 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/25 14:18:27 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_export(char **envp, char **vars, bool print)
{
    char **tmp;

    tmp = NULL;
    if (print)
        printEnvp(envp);
    else
    {
        tmp = check_duplicate(vars);
        envp = addEnvp(envp, tmp);
    }
    // (void)print;
    // (void)vars;
    for (int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);
}