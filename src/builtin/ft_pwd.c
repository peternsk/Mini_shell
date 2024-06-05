
#include "minishell.h"

void	ft_pwd(void)
{
	char	str[PATH_MAX];

	printf("%s\n", getcwd(str, PATH_MAX));
}

