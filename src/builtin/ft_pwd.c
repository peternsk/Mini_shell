/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:09:42 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/24 01:52:42 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_pwd()
{
    char    str[PATH_MAX];
    return (printf("%s\n", getcwd(str, PATH_MAX)), getcwd(str, PATH_MAX));
}