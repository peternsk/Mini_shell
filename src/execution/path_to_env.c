#include "../../include/minishell.h"

static char	*find_path_in_env(char **env)
{
	int	i; 

	i = -1;
	while (env[++i])
	{
		if (env[i][0] == 'P' & env[i][1] == 'A' & env[i][2] == 'T')
		{
			return (env[i] + 5);
		}
	}
	return (NULL);
}

static char	*get_cmd(char **them_paths, char *cmd)
{
	int		i;
	char	*cmd_temp;
	char	*real_cmd;

	i = -1;
	while (them_paths[++i])
	{
		cmd_temp = ft_strjoin(them_paths[i], "/");
		real_cmd = ft_strjoin(cmd_temp, cmd);
		free(cmd_temp);
		if (access(real_cmd, F_OK) == 0)
			return (real_cmd);
		free(real_cmd);
	}
	return (NULL);
}

static void create_pipes(int *pipes, int nb_cmds)
{
	int i;

	i = -1;
	while (++i < nb_cmds - 1)
	{
		if (pipe(pipes[2 * i]) < 0)
			break;//freethings;
	}
}

static int exec_child(t_cmdlts cmd, char **env)
{
	execve(cmd.cmd[0], cmd.cmd, env);
	return (0);
}

int main(int argc, char **argv, char **env)
{	
	pid_t	*pids;
	int		*pipes;
	t_info	info;
	t_cmdlts cmdlts;
	int i;

	info.cmdlts = &cmdlts;
	info.env_path = find_path_in_env(env);
	info.them_paths = ft_split(info.env_path, ':');
	info.nb_cmds =  cmdlts.prev->index + 1;
	i = -1;
	while(++i < info.nb_cmds)
	{
		if(!get_cmd(info.them_paths, cmdlts.cmd[0]))
			return(ERR_CMD);
		cmdlts = *cmdlts.next;
	}
	pids = malloc(sizeof(pid_t) * info.nb_cmds);
	if (!pids)
		msg_error(ERR_PID);
	pipes = malloc(sizeof(int) * (info.nb_cmds - 1) * 2);
	if (!pipes)
		msg_error(ERR_PIPE);
	create_pipes(&pipes, info.nb_cmds);
	i = -1;
	while (++i < info.nb_cmds)
	{
		while (cmdlts.index != i)
			cmdlts = *cmdlts.next;
		
		pids[i] = fork();
		if (pids[i] == 0)
			exec_child(cmdlts, env);
	}

	
    return (0);
}
