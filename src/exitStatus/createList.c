#include "minishell.h"

t_exit_code   *init_exit_lst(t_exit_code *node, pid_t extCode)
{
    node = malloc_and_add(sizeof(t_exit_code));
    if(!node)
        return(0);
    node->prev = NULL;
    node->pid = extCode;
    node->next = NULL;
    return(node);
}

void	add_exit_to_end(t_exit_code **lst, t_exit_code *var)
{
	t_exit_code	*last;
	
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

t_exit_code     *create_exitCode_lst(t_minish *m_s, pid_t extCode)
{
	t_exit_code *hereNode;

	hereNode = NULL;
    add_exit_to_end(&m_s->extlst, init_exit_lst(hereNode, extCode));
    return(m_s->extlst);
}

/*====================================================*/
/*=                    PRINT TEST                    =*/
/*====================================================*/

void	print_extLst_lst(t_exit_code *lst)
{
	t_exit_code *last;
	
	last = lst;
	if(last == NULL )
		printf("empty list\n");
	while(last != NULL)
	{
		printf("========== HERE STR ==============\n");
		printf("= node prev  : %p           \n", last->prev);
		printf("= node EC    : %d          \n", last->pid);
		printf("= node next  : %p           \n", last->next);
		printf("===============================\n");
		printf("                 =\n");
		printf("                 =\n");
		last = last->next;
	}
}