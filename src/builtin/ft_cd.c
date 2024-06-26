/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:14:20 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:14:22 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home_path(char *envp)
{
	int	i;

	i = 0;
	while (envp[i] != '=')
		i++;
	i++;
	return (envp + i);
}

char	*from_envp_get_home(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "HOME=", ft_strlen("HOME=")) == 0)
			return (get_home_path(envp[i]));
		i++;
	}
	return (NULL);
}

char	*get_live_path(void)
{
	char	str[PATH_MAX];

	return (getcwd(str, PATH_MAX));
}

void	expansion_change_directory(t_cmd *cmd, char **pwd_change)
{
	if (chdir(cmd->av_cmd[1]) == 0)
	{
		pwd_change[2] = ft_strjoin("PWD=", get_live_path());
		add_garbage(pwd_change[2]);
		is_add_envp(cmd->glob->env_varlst, pwd_change);
		g_exit_status = 0;
	}
	else
	{
		write(2, "minishell: ", ft_strlen("minishell: "));
		perror(cmd->av_cmd[1]);
		g_exit_status = 1;
	}
}

void	ft_cd(t_cmd *cmds)
{
	char	**pwd_change;

	pwd_change = (char **)malloc(sizeof(char *) * 4);
	pwd_change[0] = ft_strdup("cd\0");
	pwd_change[3] = NULL;
	pwd_change[1] = ft_strjoin("OLDPWD=", get_live_path());
	if (!cmds->av_cmd[1])
	{
		chdir(from_envp_get_home(cmds->envp));
		pwd_change[2] = ft_strjoin("PWD=", get_live_path());
		is_add_envp(cmds->glob->env_varlst, pwd_change);
		g_exit_status = 0;
	}
	else
		expansion_change_directory(cmds, pwd_change);
}
