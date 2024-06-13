/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:18:42 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/12 10:06:40 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_curr_cmd(void)
{
	t_cmd	*node;

	node = malloc_and_add(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->av_cmd = NULL;
	node->cmd_name = NULL;
	node->envp = NULL;
	node->is_file_on = 0;
	node->nb_cmds = 0;
	node->nb_pipes = 0;
	node->is_vars = false;
	node->id = -1;
	node->type = -1;
	node->exit_here_doc = 0;
	node->files = NULL;
	node->next = NULL;
	node->glob = NULL;
	return (node);
}

char	**extra_init_cmds(t_minish *m_s, t_cmd *curr, char **tmp)
{
	t_cmd		*new;
	t_cmdlts	*curr_list;

	new = NULL;
	curr_list = NULL;
	curr_list = m_s->comd_lst;
	while (curr_list != NULL)
	{
		new = init_curr_cmd();
		new->cmd_name = *curr_list->command;
		new->glob = m_s;
		new->envp = list_to_tab(&m_s->env_varlst);
		new->files = curr_list->redlst;
		new->type = type_cmds(new->cmd_name);
		new->av_cmd = curr_list->command;
		add_cmds(&curr, new);
		curr_list = curr_list->next;
	}
	cout_cmds_pipes(curr);
	run_commands(curr);
	tmp = list_to_tab(&curr->glob->env_varlst);
	return (tmp);
}

char	**init_cmds(char **tmp, t_minish *m_s)
{
	t_cmd		*curr;
	// t_cmdlts	*curr_list;

	curr = NULL;
	// curr_list = NULL;
	m_s->index = 0;
	if (m_s->comd_lst)
	{
		tmp = extra_init_cmds(m_s, curr, tmp);
		add_filename_unlnk_lst(&m_s->comd_lst, m_s);
	}
	return (tmp);
}
