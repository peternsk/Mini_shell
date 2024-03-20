// #include "../../include/minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "../../libft/ft_split.c"
#include "../../libft/ft_strjoin.c"
#include "../../libft/ft_strlen.c"
#include "../../libft/ft_substr.c"
#include <stdlib.h>
#include <sys/wait.h>
#include "../../include/error.h"
#include "error.c"

typedef	struct s_cmdlts
{
	struct s_cmdlts *prev;
	struct s_cmdlts *next;
	int	index;
	// linked redirect
	char **cmd; // cmd -option args
}	t_cmdlts;

typedef struct s_info
{
	t_cmdlts *cmdlts;
	int		nb_cmds;
	char	*env_path;
	char	**them_paths;
	char	**cmd_args;
	int		*pipes;
}   t_info;

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
		if (pipe(&pipes[2 * i]) < 0)
			break;//freethings;
	}
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

static int exec_child(pid_t pid, t_info *info, char **env)
{
	pid = fork();
	if (pid == 0)
	{
		if (info->cmdlts->index == info->nb_cmds - 1)
			sub_dup2(info->pipes[2 * info->cmdlts->index - 1], STDOUT_FILENO);
		else if (info->cmdlts->index == 0)
			sub_dup2(STDIN_FILENO, info->pipes[2 * info->cmdlts->index]);
		else
			sub_dup2(info->pipes[2 * info->cmdlts->index - 1], info->pipes[2 * info->cmdlts->index]);
		info->cmdlts->cmd[0] = get_cmd(info->them_paths, info->cmdlts->cmd[0]);
		execve(info->cmdlts->cmd[0], info->cmdlts->cmd, env);
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{	
	pid_t	pid;
	t_info	info;
	t_cmdlts cmdlts;
	t_cmdlts cmdlts2;

	int i;

	cmdlts.cmd = malloc (sizeof(char *) * 3);
	cmdlts2.cmd = malloc (sizeof(char *) * 3);
	cmdlts.cmd[0] = "echo";
	cmdlts.cmd[1] = "Bonjour";
	cmdlts2.cmd[0] = "echo";
	cmdlts2.cmd[1] = "J'aime les pommes";
	cmdlts.next = &cmdlts2;
	cmdlts.prev = &cmdlts2;
	cmdlts2.next = &cmdlts;
	cmdlts2.prev = &cmdlts;
	cmdlts.index = 0;
	cmdlts2.index = 1;
	info.cmdlts = &cmdlts;
	info.env_path = find_path_in_env(env);
	info.them_paths = ft_split(info.env_path, ':');
	info.nb_cmds =  cmdlts.prev->index + 1;
	i = -1;
	while(++i < info.nb_cmds)
	{
		if(!get_cmd(info.them_paths, info.cmdlts->cmd[0]))
			msg_error(ERR_CMD);
		info.cmdlts = info.cmdlts->next;
	}
	// pids = malloc(sizeof(pid_t) * info.nb_cmds);
	// if (!pids)
	// 	msg_error(ERR_PID);
	// execve(info.cmdlts->cmd[0], info.cmdlts->cmd, env);
	
	info.pipes = malloc(sizeof(int) * (info.nb_cmds - 1) * 2);
	if (!info.pipes)
		msg_error(ERR_PIPE);
	create_pipes(info.pipes, info.nb_cmds);
	i = -1;
	while (++i < info.nb_cmds)
	{
		// while (info.cmdlts->index != 0)
		// 	info.cmdlts = info.cmdlts->next;
		exec_child(pid, &info, env);
		info.cmdlts = info.cmdlts->next;
	}
	wait(NULL);
	
    return (0);
}
