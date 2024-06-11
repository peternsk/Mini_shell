
#include "minishell.h"

int	size(char **env)
{
	int	i;

	i = 0;
	if (env)
		while (env[i] != NULL)
			i++;
	return (i);
}
