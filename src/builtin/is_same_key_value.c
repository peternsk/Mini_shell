
#include "minishell.h"

int	is_same_key_value(t_env *env, char *var, int index)
{
	t_env	*node;
	char	*pars_var;
	int		i;

	i = 0;
	node = env;
	if (env && var && is_key(var) == true)
	{
		pars_var = ft_strchr(var, '=');
		pars_var++;
		while (node != NULL)
		{
			if (index == i)
			{
				if (ft_strcmp(node->value, pars_var) == false)
					return (i);
			}
			i++;
			node = node->next;
		}
		return (-1);
	}
	return (-3);
}
