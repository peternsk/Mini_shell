
#include "minishell.h"

t_cmdlts	*set_cmd_node(t_cmdlts *cmd, t_minish *m_s)
{
	cmd = malloc_and_add(sizeof(t_cmdlts));
	if (!cmd)
		return (0);
	cmd->prev = NULL;
	cmd->arr_len = -1;
	cmd->index = m_s->index;
	m_s->index = m_s->index + 1;
	cmd->command = (char **)malloc_and_add((sizeof(char *) * 150) + 1);
	if (!cmd->command)
		return (0);
	cmd->redlst = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	add_cmd_node_to_end(t_cmdlts **lst, t_cmdlts *cmd)
{
	t_cmdlts	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = cmd;
		cmd->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = cmd;
	cmd->prev = last;
}

int	ft_nbr_of_node(t_token **lst)
{
	t_token	*last;
	int		node_needed;

	last = *lst;
	node_needed = 1;
	while (last != NULL)
	{
		if (last->type == pipe_)
			node_needed++;
		last = last->next;
	}
	return (node_needed);
}


void	ft_createcomd_lst(t_minish *m_s)
{
	t_cmdlts	*cmd;
	int			nb_of_node;

	cmd = NULL;
	m_s->index = 0;
	nb_of_node = ft_nbr_of_node(&m_s->token_lst);
	while (nb_of_node > 0)
	{
		add_cmd_node_to_end(&m_s->comd_lst, set_cmd_node(cmd, m_s));
		nb_of_node--;
	}
}
