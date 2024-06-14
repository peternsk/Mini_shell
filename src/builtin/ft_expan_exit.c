/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expan_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:35:33 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/06/13 23:29:04 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_extra_exit(char *vars)
{
	int	i;

	i = 0;
	if (vars)
	{
		while (vars[i] != '\0')
		{
			if (ft_isdigit(vars[i]) == 1)
				i++;
			else
				break ;
		}
		if ((size_t)i == ft_strlen(vars))
			return (true);
	}
	return (false);
}

bool	expand_exit(char **vars)
{
	int	i;

	i = 1;
	if (vars)
	{
		if (ft_extra_exit(vars[i]) == true)
		{
			write(2, "exit: too many arguments\n",
				ft_strlen("exit: too many arguments\n"));
			return (true);
		}
	}
	write(2, "exit: numeric argument required\n",
		ft_strlen("exit: numeric argument required\n"));
	return (false);
}
