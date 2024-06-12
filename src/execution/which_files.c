/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:20:33 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:54:27 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_last_files(t_files *files, int type)
{
	t_files	*node;
	t_files	*tmp;

	tmp = NULL;
	node = files;
	if (files)
	{
		while (node != NULL)
		{
			if (node->type == type)
				tmp = node;
			node = node->next;
		}
		if (tmp)
			tmp->put_last = 1;
	}
}

void	ticket_files(t_cmd *cmd)
{
	check_last_files(cmd->files, here_doc);
	check_last_files(cmd->files, IPR);
	check_last_files(cmd->files, APOR);
	check_last_files(cmd->files, OPR);
}

void	change_stdint_cmd(t_cmd *current)
{
	t_files	*out;
	int		fd;

	out = give_last_file_stdout(current->files);
	if (out)
	{
		out->manage_fd = dup(1);
		if (out->type == APOR)
			fd = open(out->name, O_WRONLY | O_APPEND, 07777);
		else
			fd = open(out->name, O_WRONLY | O_CREAT | O_TRUNC, 07777);
		dup2(fd, 1);
		close(fd);
	}
}

void	which_files(t_cmd *current)
{
	t_files	*files;
	t_cmd	*cmd;

	cmd = current;
	while (cmd != NULL)
	{
		ticket_files(cmd);
		files = cmd->files;
		if (cmd->files)
		{
			change_stdint(cmd->files);
			if (is_files_valide(cmd) == 0)
			{
				ft_append(cmd->files);
				change_stdout(cmd->files);
				if (current->nb_cmds == 1)
					change_stdint_cmd(current);
			}
		}
		cmd = cmd->next;
	}
	expan_here_doc(current);
}
