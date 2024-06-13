/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:14:39 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:14:41 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_cmd *env)
{
	t_env	*curr;

	if (!env->glob->env_varlst)
		return ;
	curr = env->glob->env_varlst;
	while (curr && curr->eql_sign == true)
	{
		printf("%s=%s\n", curr->key, curr->value);
		curr = curr->next;
	}
}
