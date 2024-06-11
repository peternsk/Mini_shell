
#include "minishell.h"

void	m_cmd_path_error(int error_type, char *message)
{
	write(error_type, "minishell: ", ft_strlen("minishell: "));
	write(error_type, message, ft_strlen(message));
	write(error_type, ": command not found\n",
		ft_strlen(": command not found\n"));
}

int	is_files_valide_single(t_cmd *cmds)
{
	t_cmd	*current;
	t_files	*curr_files;

	current = cmds;
	if (current)
	{
		if (current->files)
		{
			curr_files = current->files;
			while (curr_files != NULL)
			{
				if (curr_files->error == -1 || current->exit_here_doc != 0)
					return (-1);
				curr_files = curr_files->next;
			}
		}
	}
	return (0);
}

int	execute_command(t_cmd *current, char *envp_path, int **array_pipe)
{
	char	*cmd_path;

	if (!current)
		return (-1);
	pipe_connect_and_files(current, array_pipe);
	current->is_file_on = is_files_valide_single(current);
	if (current->type == 8 && current->is_file_on == 0)
		handel_builtin(current);
	else if (current->is_file_on == 0 && current->type != -1)
	{
		cmd_path = get_cmd_path(envp_path, current->cmd_name);
		if (!cmd_path)
			return (m_cmd_path_error(2, current->cmd_name), exit(127), 0);
		if (execve(cmd_path, current->av_cmd, current->envp) == -1)
			return (perror(current->cmd_name), exit(EXIT_FAILURE), 0);
		return (1);
	}
	return (exit(g_exit_status), 0);
}

