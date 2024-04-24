/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:11:15 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/24 01:47:41 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *get_home_path(char *envp)
{
    int i;

    i = 0;
    while (envp[i] != '=')
         i++;
    i++;
    return (envp + i);
}

char    *form_envp_get_home(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "HOME=", ft_strlen("HOME=")) == 0)
            return (get_home_path(envp[i]));
        i++;
    }
    return (NULL);
}
int root_directory(char **envp)
{
    const char    *path;

    path = form_envp_get_home(envp);
    if (chdir(path) == 0)
        ft_pwd();
    return (0);
}
void    expansion_change_directory(t_cmd *cmds)
{
    if (cmds->av_cmd[1] != NULL)
    {   
        if (chdir(cmds->av_cmd[1]) == 0)
            ft_pwd();
        else
            perror("minishell");
    }
}
// TODO: maybe change the function for better error handling
void    ft_cd(t_cmd *cmds)
{
    if (ft_strncmp(cmds->cmd_name, "cd", 2) == 0)
    {
        if (!cmds->av_cmd[1])
            root_directory(cmds->envp);
        else 
            expansion_change_directory(cmds);
    }
}
