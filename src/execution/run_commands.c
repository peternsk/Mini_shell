/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:19:46 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:19:48 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_commands(t_cmd *cmds)
{
	char	*envp_path;

	if (!cmds)
		return (-1);
	envp_path = get_envp_path(cmds->envp);
	if (cmds->nb_cmds == 1 && cmds->nb_pipes == 0)
	{
		if (single_command(cmds, cmds->envp, envp_path) == -1)
			return (-1);
	}
	else
		commands(cmds, envp_path);
	return (1);
}
