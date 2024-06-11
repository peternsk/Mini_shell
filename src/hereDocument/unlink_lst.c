
#include "minishell.h"

t_unlnk	*int_unlnk_node(t_unlnk *node, char *filepath)
{
	node = malloc_and_add(sizeof(t_unlnk));
	if (!node)
		return (0);
	node->filepath_name = ft_strdup(filepath);
	add_garbage(node->filepath_name);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_file_to_end(t_unlnk **lst, t_unlnk *node)
{
	t_unlnk	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		node->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = node;
	last->prev = last;
}

t_unlnk	*create_unlnk_node(t_minish *m_s, char *filepath)
{
	t_unlnk	*filepath_node;

	filepath_node = NULL;
	add_file_to_end(&m_s->unlnk_lst, int_unlnk_node(filepath_node, filepath));
	return (m_s->unlnk_lst);
}

void	unlnk_all_file(t_unlnk **lst)
{
	t_unlnk	*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp != NULL)
	{
		unlink(tmp->filepath_name);
		tmp = tmp->next;
	}
}

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

void	add_filename_unlnk_lst(t_cmdlts **cmd, t_minish *m_s)
{
	t_cmdlts	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		create_filename_linklist(m_s, &tmp->redlst);
		tmp = tmp->next;
	}
	unlnk_all_file(&m_s->unlnk_lst);
}
