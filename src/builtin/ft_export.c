/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:15:09 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:15:11 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**free_array(char **vars)
{
	int	i;

	i = 0;
	while (vars[i] != NULL)
	{
		free(vars[i]);
		i++;
	}
	vars = NULL;
	return (vars);
}

void	ft_export(t_cmd *built, bool print)
{
	if (print == true)
		print_envp(built->envp);
	else
		is_add_envp(built->glob->env_varlst, built->av_cmd);
}
