/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:14:27 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:14:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_line(char **av)
{
	if (ft_strncmp(av[1], "-n", ft_strlen("-n")) == 0)
		return (true);
	return (false);
}

bool	is_newline(char *av, int index)
{
	int	i;

	i = 0;
	(void)index;
	if (av)
	{
		if (av[i] == '-')
		{
			i++;
			while (av[i] != '\0' && av[i] == 'n')
				i++;
		}
		if (i == (int)ft_strlen(av) && ft_strlen(av) != 0)
			return (true);
	}
	return (false);
}

void	ft_echo(t_cmd *ec)
{
	int		i;
	bool	new_line;

	i = 1;
	new_line = false;
	while (i < size(ec->av_cmd))
	{
		if (ec->av_cmd[i])
		{
			new_line = is_newline(ec->av_cmd[i], i);
			if (new_line == false)
			{
				printf("%s", ec->av_cmd[i]);
				if (ec->av_cmd[i + 1] != NULL)
					printf(" ");
			}
		}
		i++;
	}
	if (size(ec->av_cmd) == 1 || is_newline(ec->av_cmd[1], 1) == false)
		printf("\n");
	g_exit_status = 0;
}
