
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

static char	*_check_absolute_path(char *cmd)
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
				return (cmd);
		}
	}
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
	{
		while (sub_paths[i])
		{
			cmd_path = ft_strjoin(sub_paths[i], "/");
			add_garbage(cmd_path);
			cmd_path = ft_strjoin(cmd_path, cmd);
			if (access(cmd_path, F_OK | X_OK) == 0)
			{
				add_garbage(cmd_path);
				return (free_str(sub_paths), cmd_path);
			}
			free(cmd_path);
			i++;
		}
		free_str(sub_paths);
	}
	return (NULL);
}


void	fake(void)
{
}
