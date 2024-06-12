/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_absolute_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:17:38 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:17:41 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_cmd_valide_path(char *cmd)
{
	int	dot;

	dot = 0;
	if (cmd)
	{
		if (cmd[0] == '.' || cmd[0] == '/')
			return (1);
		while (cmd[dot] != '\0' && (cmd[dot] == '.' || cmd[dot] == '/'))
			dot++;
	}
	return (dot);
}

char	*_check_absolute_path(char *cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		while (cmd[i] != '\0' && (cmd[i] == '.' || cmd[i] == '/'))
			i++;
		if (i > 0)
		{
			if (access(cmd, F_OK | X_OK) == 0)
				return (g_exit_status = 0, cmd);
		}
	}
	return (g_exit_status = 127, NULL);
}