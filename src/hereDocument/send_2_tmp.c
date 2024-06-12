/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_2_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:24:38 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/12 10:20:06 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	send_2_tmp(t_heredoc **lst, t_minish *m_s, t_files *tmp_files,
		int index)
{
	t_heredoc	*tmp;
	int			fd;

	tmp = *lst;
	tmp_files->name_here_doc = ft_strjoin("/tmp/heredoc", ft_itoa(index));
	add_garbage(tmp_files->name_here_doc);
	fd = open(tmp_files->name_here_doc, O_RDWR | O_CREAT | O_TRUNC, 07777);
	while (tmp)
	{
		if (tmp->made == false)
		{
			herelist_exp(lst, &m_s->env_varlst, m_s);
			ft_putstr_fd(tmp->str, fd);
			tmp->made = true;
		}
		tmp = tmp->next;
	}
	close(fd);
}
