/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:26:38 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/22 23:28:30 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

static char    *_check_absolute_path(char *cmd)
{
    if (!cmd)
        return (NULL);
    if (cmd[0] == '/')
        if (access(cmd, F_OK) == 0)
            return (cmd);
    return (NULL);
}

char    *get_cmd_path(char *path, char *cmd)
{
    char    **sub_paths;
    int 	i;
    char    *cmd_path;

    cmd_path = _check_absolute_path(cmd);
    if (cmd_path != NULL)
        return (cmd_path);
    sub_paths = ft_split(path, ':');
    i = 0;
    while (sub_paths[i])
    {
        cmd_path = ft_strjoin(sub_paths[i], "/"); // TODO: Caching system (key -> value)
        cmd_path = ft_strjoin(cmd_path, cmd);
        if (access(cmd_path, F_OK) == 0)
            return (free_str(sub_paths), cmd_path);
        free(cmd_path);
        i++;
    }
    free_str(sub_paths);
    return (NULL);
}