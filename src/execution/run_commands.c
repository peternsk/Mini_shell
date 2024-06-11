
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
