#include "../../include/minishell.h"

static char	*extract_cmd(char *raw_cmd)
{
	int		i;
	char	*cmd;

	i = 0;
	while (raw_cmd[i] != ' ')
		i++;
	cmd = malloc(sizeof(char) * (i + 2));
	if (!cmd)
		return (NULL);
	i = 0;
	cmd[i] = '/';
	while (raw_cmd[i] != ' ')
	{
		cmd[i + 1] = raw_cmd[i];
		i++;
	}
	cmd[i + 1] = '\0';
	return (cmd);
}

static char	*extract_args(char *raw_cmd, char *cmd)
{
	char	*args;

	args = ft_strtrim(raw_cmd, (const char *)cmd);
	if (args[0] != '\0')
	{
		args = ft_strtrim(args, " ");
		return (args);
	}
	free(args);
    return (NULL);
}

static int	find_path_in_env(char **env, char *tofind)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (j < (int)ft_strlen(tofind))
		{
			if (env[i][j] != tofind[j])
				break ;
			j++;
		}
		if (j == (int)ft_strlen(tofind))
			return (i);
		i++;
	}
	return (-1);
}

static char	*find_path(char **env, char *cmd)
{
	int		i;
	char	*path;
	char	**them_paths;

	path = ft_strtrim(env[find_path_in_env(env, "PATH=")], "PATH=");
	if (!path)
		return (NULL);
	them_paths = ft_split(path, ':');
	if (!them_paths)
		return (NULL);
	i = 0;
	while (them_paths[i])
	{
		path = ft_strjoin(them_paths[i], cmd);
		if (access(path, F_OK))
			break ;
		free(path);
		i++;
	}
	return (path);
}

int test(void)
{
    return (0);
}
