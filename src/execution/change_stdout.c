/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:17:30 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/12 09:19:37 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	put_int_fd(t_files *file)
{
	int	fd_name;

	if (file->name && file->made == 0)
	{
		file->made = 1;
		fd_name = open(file->name, O_WRONLY | O_CREAT, 07777);
		if (fd_name < 0)
			return (perror(file->name), file->error = -1, g_exit_status = 1,
				-1);
		g_exit_status = 0;
		close(fd_name);
	}
	return (-1);
}

int	change_stdout(t_files *files)
{
	t_files	*current;

	if (files)
	{
		current = files;
		while (current != NULL)
		{
			if (current->type == OPR)
				put_int_fd(current);
			if (current->error == -1)
				return (-1);
			current = current->next;
		}
	}
	return (-1);
}
