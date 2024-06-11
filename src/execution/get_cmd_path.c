
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

char	*get_current_path(void)
{
	char	str[PATH_MAX];

	return (getcwd(str, PATH_MAX));
}


char 	*extra_path_check(char **sub_paths, char *cmd_path, char *cmd)
{
	int	i;

	i = 0;
	while (sub_paths[i])
	{
		cmd_path = ft_strjoin(sub_paths[i], "/");
		add_garbage(cmd_path);
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			add_garbage(cmd_path);
			return (g_exit_status = 0, free_str(sub_paths), cmd_path);
		}
		g_exit_status = 127;
		free(cmd_path);
		i++;
	}
	free_str(sub_paths);
	return (NULL);
}
char	*get_cmd_path(char *path, char *cmd) // 25 lines
{
	char	**sub_paths;
	int		i;
	char	*cmd_path;

	cmd_path = _check_absolute_path(cmd);
	if (cmd_path != NULL)
		return (cmd_path);
	if (cmd_path == NULL && is_cmd_valide_path(cmd) > 0)
		return (NULL);
	sub_paths = ft_split(path, ':');
	i = 0;
	if (sub_paths)
		return (extra_path_check(sub_paths, cmd_path, cmd));
	return (NULL);
}

