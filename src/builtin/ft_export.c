/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:18:05 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/23 21:18:08 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_export(char **envp, char **vars, bool print)
{
    if (print)
        printEnvp(envp);
    else
        envp = addEnvp(envp, vars);
    for (int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);
}