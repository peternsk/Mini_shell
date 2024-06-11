
#include "minishell.h"

void	close_pipe(t_cmd *cmds, int **array_pipe)
{
	int	i;

	i = 0;
	while (i < (cmds)->nb_cmds - 1)
	{
		close(array_pipe[i][0]);
		close(array_pipe[i][1]);
		i++;
	}
}

int	**create_pipe(t_cmd *cmd)
{
	int	**array;
	int	i;

	i = 0;
	array = 0;
	if (cmd && cmd->nb_cmds > 1)
	{
		array = malloc_and_add((cmd->nb_cmds - 1) * sizeof(int *));
		while (i < (cmd->nb_cmds - 1))
		{
			array[i] = malloc_and_add(sizeof(int) * 2);
			pipe(array[i]);
			i++;
		}
	}
	return (array);
}

void	here_doc_cmds(t_cmd *cmds)
{
	t_cmd	*now_shine;

	now_shine = cmds;
	while (now_shine != NULL)
	{
		if (is_there_here_doc(now_shine) > 0)
		{
			run_here_redlst(now_shine->glob, &now_shine->files);
			herelist_exp(&now_shine->glob->herelst,
				&now_shine->glob->env_varlst, now_shine->glob);
		}
		now_shine = now_shine->next;
	}
}

int	commands(t_cmd *cmds, char *envp_path)
{
	t_cmd	*curr;
	int		**array_pipe;

	which_files(cmds);
	array_pipe = create_pipe(cmds);
	curr = cmds;
	while (curr != NULL)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		curr->id = fork();
		if (curr->id == 0)
		{
			printf("=== in commands ===\n");
			manage_signal(0);
			execute_command(curr, envp_path, array_pipe);
		}
		else if (curr->id < 0)
			printf("Error fork()\n");
		else
			curr = curr->next;
	}
	close_pipe(cmds, array_pipe);
	return (wait_childs(cmds), 1);
}
