#include "minishell.h"

t_unlnk 	*int_unlnk_node(t_unlnk *node, char *filepath)
{
	node = malloc_and_add(sizeof(t_unlnk));
	if(!node)
		return(0);
	node->prev = NULL;
	node->filepath_name = ft_strdup(filepath);
	add_garbage(node->filepath_name);
	node->next = NULL;
	return(node);
}

void	add_file_to_end(t_unlnk **lst, t_unlnk *var)
{
	t_unlnk	*last;
	
	if(!lst)
		return;
	if(*lst == NULL)
	{
		*lst = var;
		var->next = NULL;
		return;	
	}
	last = *lst;
	while(last->next != NULL)
		last = last->next;
	last->next = var;
	var->prev =last;
}

t_env     *create_unlnk_node(t_minish *m_s, char *filepath)
{
	t_unlnk *filepath_node;

	filepath_node = NULL;
    add_file_to_end(&m_s->unlnk_lst, int_unlnk_node(filepath_node, filepath));
    return(m_s->unlnk_lst);
}

void	unlnk_all_file(t_unlnk **lst)
{
	t_unlnk *tmp;

	tmp = *lst;
	while(tmp)
	{
		unlink(tmp->filepath_name);
		tmp = tmp->next;
	}
}