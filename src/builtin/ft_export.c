/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:18:05 by mnshimiy          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/13 15:50:26 by mnshimiy         ###   ########.fr       */
=======
/*   Updated: 2024/05/13 18:44:47 by mnshimiy         ###   ########.fr       */
>>>>>>> 1a329b367cc70498fe31e0ca488f187333bda6b6
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
    // printf("==========================================\n");
    // for (int i = 0; envp[i] != NULL; i++)
    //     printf("%s\n", envp[i]);
}