
#include "minishell.h"

void	cmd_path_error(int error_type, char *message)
{
	write(error_type, "minishell: ", ft_strlen("minishell: "));
	write(error_type, message, ft_strlen(message));
	write(error_type, ": command not found\n",
		ft_strlen(": command not found\n"));
}

int	execute_one_command(t_cmd *current, char **envp, char *envp_path)
{
	char	*cmd_path;

	if (!current)
		return (printf("current is NULL"), -1);
	if (current->nb_cmds > 1 && current->nb_pipes > 0 && current->type == 8)
		exit(handel_builtin(current));
	else
	{
		cmd_path = get_cmd_path(envp_path, current->cmd_name);
		if (!cmd_path)
			return (cmd_path_error(2, current->cmd_name), exit(g_exit_status),
				0);
		if (execve(cmd_path, current->av_cmd, envp) == -1)
			return (perror(cmd_path), exit(126), 0);
		return (1);
	}
	return (0);
}

int	the_last_heredoc(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->files)
	{
		if (cmd->files->type == here_doc)
			i++;
		cmd->files = cmd->files->next;
	}
	return (i);
}

static void	extra_single_command(t_cmd *cmd, char **envp, char *envp_path)
{
	manage_signal(0);
	std_one_commande(cmd);
	execute_one_command(cmd, envp, envp_path);
}

int	single_command(t_cmd *cmd, char **envp, char *envp_path)
{
	t_files	*last;

	last = NULL;
	if (cmd)
	{
		which_files(cmd);
		cmd->is_file_on = is_files_valide(cmd);
		if (cmd->type == 8 && cmd->is_file_on == 0)
			handel_builtin(cmd);
		else if (cmd->type != -1 && cmd->is_file_on == 0)
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			cmd->id = fork();
			if (cmd->id == 0)
				extra_single_command(cmd, envp, envp_path);
			else
				wait_childs(cmd);
		}
		last = give_last_file_stdout(cmd->files);
		if (last)
			dup2(last->manage_fd, 1);
	}
	return (0);
}
