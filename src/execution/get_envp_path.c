
#include "minishell.h"

static char	*_without_path(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] == s2[i]) && (s1[i] != '\0') && s2[i] != '\0')
			i++;
		return (s2 + i);
	}
	return (NULL);
}

char	*get_envp_path(char **envp)
{
	int	index;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp("PATH=", envp[index], ft_strlen("PATH=")) == 0)
			return (_without_path("PATH=", envp[index]));
		index++;
	}
	return (NULL);
}
