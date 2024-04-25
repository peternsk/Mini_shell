/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:11:15 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/25 17:24:05 by mnshimiy         ###   ########.fr       */
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
void    expansion_change_directory(t_cmd *cmds)
{
    char str[PATH_MAX];
    char *oldPwd;
    char **newPwd;

    oldPwd = NULL;
    newPwd = malloc(sizeof(char *) * 2);
    if (!newPwd)
        return;
    newPwd[1] = NULL;
    if (cmds->av_cmd[1] != NULL)
    {  
        oldPwd = getcwd(str, PATH_MAX);
        if (chdir(cmds->av_cmd[1]) == 0)
        {
            newPwd[0] = ft_strjoin("PWD=", getcwd(str, PATH_MAX));
            printf("%s ---- --- \n", newPwd[0]);
            ft_export(cmds->envp, newPwd, false);
            for (int i = 0; cmds->envp[i] != NULL; i++)
                printf("%s\n", cmds->envp[i]);
        }
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
            chdir(form_envp_get_home(cmds->envp));
        else 
            expansion_change_directory(cmds);
    }
}
