
#include "minishell.h"

void	change_key_value(t_env **env, char *vars)
{
	char	*var_parsing;

	var_parsing = NULL;
	if (env && vars)
	{
		var_parsing = ft_strchr(vars, '=');
		if (var_parsing)
		{
			var_parsing++;
			if (ft_strcmp((*env)->value, var_parsing) == false)
			{
				free((*env)->value);
				(*env)->value = NULL;
				(*env)->value = copy_value(vars);
				(*env)->eql_sign = true;
			}
		}
	}
}

void	where_to_envp(t_env **env, char *vars, int index)
{
	t_env	*node;
	t_env	*new_node;
	int		i;

	node = *env;
	new_node = NULL;
	i = 0;
	if (vars)
		if (index > 0)
		{
			while (node != NULL)
			{
				if (i == index)
				{
					change_key_value(&node, vars);
					break ;
				}
				i++;
				node = node->next;
			}
		}
	if (index == -1)
		add_var_to_end(env, int_env_var(new_node, vars));
}

char	*copy_key_pars(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	if (str)
	{
		while (str[i] != '\0' && str[i] == '=')
			i++;
		new = malloc_and_add(sizeof(char *) * (i + 1));
		if (!new)
			return (NULL);
		i = 0;
		while (str[i] != '\0' && str[i] != '=')
		{
			new[i] = str[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}

bool is_meta_export(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (str[i] == '-' || str[i] == '$' || str[i] == '+' || str[i] == '!' || str[i] == '#')
		{
            write(2, "export: not a valid identifier\n", ft_strlen("export: not a valid identifier\n"));
            g_exit_status = 1;
			return (true);
		}
		i++;
	}
	return (false);
}
int is_valide(char *str)
{
    bool is;
    int i;

    i = 0;
    is = false;
	if (is_meta_export(str) == true)
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 1)
			is = true;
		if (ft_isalpha(str[i]) == 0 && is == false)
		{
			write(2, "export: not a valid identifier\n", ft_strlen("export: not a valid identifier\n"));
			g_exit_status = 1;
			return (1);
		}
		i++;
	}
    return (0);
}

void	is_add_envp(t_env *old_envp, char **arg)
{
	t_env	*node;
	char	**vars;
	int		add;
	int		i;

    i = 0;
    node = old_envp;
    vars = check_duplicate(arg);
	printf("tag 1\n");
    while (vars[i] != NULL)
    {
        if (is_valide(vars[i]) == 0)
        {
            g_exit_status = 0;
            add = is_same_key(node, copy_key_pars(vars[i]));
            if (is_key(vars[i]) == true)
            {
                is_same_key_value(node, vars[i], add); 
                where_to_envp(&old_envp, vars[i], add);
            }
            else
                where_to_envp(&old_envp, vars[i], add);
        }
        i++;
    }
}
