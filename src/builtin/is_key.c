
#include "minishell.h"

bool	is_key(char *var)
{
	char	*look;

	look = ft_strchr(var, '=');
	if (look)
	{
		look++;
		if (ft_strlen(look) > 0)
			return (true);
	}
	return (false);
}
