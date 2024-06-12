/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_unlnk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:21:06 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:53:57 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_filename_linklist(t_minish *m_s, t_files **lst)
{
	t_files	*tmp;
	int		here_nbr;

	tmp = *lst;
	here_nbr = count_here_doc(lst);
	while (tmp)
	{
		tmp->name_here_doc = ft_strjoin("/tmp/heredoc",
				ft_int_to_ascii(tmp->heredoc_id));
		add_garbage(tmp->name_here_doc);
		if ((tmp->type == here_doc) && (tmp->heredoc_id < here_nbr)
			&& tmp->here_count == 0)
			tmp->here_count = -1;
		if ((tmp->type == here_doc) && tmp->here_count == 0)
		{
			tmp->here_count = -1;
			create_unlnk_node(m_s, tmp->name_here_doc);
		}
		tmp = tmp->next;
	}
}
