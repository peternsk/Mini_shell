
#include "minishell.h"

void	ft_env(t_cmd *env)
{
	if (!env->glob->env_varlst)
		return ;
	while (env->glob->env_varlst && env->glob->env_varlst->eql_sign == true)
	{
		printf("%s=%s\n", env->glob->env_varlst->key,
			env->glob->env_varlst->value);
		env->glob->env_varlst = env->glob->env_varlst->next;
	}
}
