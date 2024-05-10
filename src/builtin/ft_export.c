/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:18:05 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/08 21:12:40 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_export(t_cmd * built, char **envp, char **vars, bool print)
{
    char **tmp;

    tmp = NULL;
    if (print)
        printEnvp(envp);
    else
    {
        tmp = check_duplicate(vars);
        // for (int i = 0; tmp[i] != NULL; i++)
        //     printf("----%s\n", tmp[i]);
        // built->envp = addEnvp(envp, tmp);
        envp = addEnvp(envp, tmp);
    }
    (void)print;
    (void)vars;
    (void)envp;
    (void)built;
    // int i = 0;
    // if (envp)
    // {
    //     while (envp[i] != NULL)
    //     {
    //         printf("%s\n", envp[i]);
    //         i++;
    //     }
    // }
    printf("==========================================\n");
    for (int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);
}