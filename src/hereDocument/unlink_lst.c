#include "minishell.h"

t_unlnk 	*int_unlnk_node(t_unlnk *node, char *filepath)
{
	node = malloc_and_add(sizeof(t_unlnk));
	if(!node)
		return(0);
	node->filepath_name = ft_strdup(filepath);
	add_garbage(node->filepath_name);
	node->next = NULL;
	printf("NODE SET]\n");
	return(node);
}

void	add_file_to_end(t_unlnk **lst, t_unlnk *node)
{
	t_unlnk	*last;
	
	if(!lst)
		return;
	if(*lst == NULL)
	{
		*lst = node;
		node->next = NULL;
		printf("FILE ADDED]\n");
		return;	
	}
	last = *lst;
	while(last->next != NULL)
		last = last->next;
	last->next = node;
	printf("FILE ADDED]\n");
}

t_unlnk     *create_unlnk_node(t_minish *m_s, char *filepath)
{
	t_unlnk *filepath_node;

	filepath_node = NULL;
	printf("ADDING FILE]\n");
    add_file_to_end(&m_s->unlnk_lst, int_unlnk_node(filepath_node, filepath));
    return(m_s->unlnk_lst);
}

void	unlnk_all_file(t_unlnk **lst)
{
	t_unlnk *tmp;

	tmp = *lst;
	printf("[IN UNLNK FNCT]\n");
	if(!tmp)
		printf("[EMPTY LIST]\n");
	while(tmp)
	{
		printf("[DELETING FILE : %s]\n", tmp->filepath_name);
		unlink(tmp->filepath_name);
		tmp = tmp->next;
	}
}