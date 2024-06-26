/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:17:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:17:24 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	put_error(t_files *current)
{
	t_files	*node;

	node = current;
	while (node != NULL)
	{
		if (node->type == IPR)
			node->error = -1;
		node = node->next;
	}
	return (0);
}

int	put_fd(t_files *current)
{
	int	fd;

	if (current->error == 0 && current->made == 0)
	{
		fd = open(current->name, O_RDONLY);
		if (fd > 0)
			return (current->made = -1, close(fd), g_exit_status = 0, 0);
		return (put_error(current), perror(current->name), close(fd),
			current->error = -1, current->made = -1, g_exit_status = 1, -1);
	}
	return (0);
}

int	change_stdint(t_files *files)
{
	t_files	*current;

	current = files;
	if (current)
	{
		while (current != NULL)
		{
			if (current->type == IPR)
				put_fd(current);
			if (current->error == -1)
				return (-1);
			current = current->next;
		}
		return (0);
	}
	return (0);
}
