
#include "minishell.h"

char	*pars_key(char *vars)
{
	int		i;
	char	*var_pars;

	i = 0;
	var_pars = malloc_and_add(sizeof(char *) * (ft_strlen(vars)));
	if (!var_pars)
		return (NULL);
	while (vars[i] != '\0' || vars[i] != '=')
	{
		var_pars[i] = vars[i];
		i++;
	}
	var_pars[i] = '\0';
	return (var_pars);
}

int	is_same_key(t_env *env, char *var)
{
	t_env	*node;
	int		i;

	node = env;
	i = 0;
	if (env && var && is_key(var) == false)
	{
		if (ft_strchr(var, '='))
			var = pars_key(var);
		while (node != NULL)
		{
			if (ft_strcmp(node->key, var) == false)
				node = node->next;
			else
				return (i);
			i++;
		}
		return (-1);
	}
	return (-3);
}
