#include "minishell.h"

t_heredoc   *intHereLst(t_heredoc *node, char *input)
{
    node = malloc_and_add(sizeof(t_heredoc));
    if(!node)
        return(0);
    node->prev = NULL;
    node->str  = ft_strdup(input);
	add_garbage(node->str);
    node->expstr = NULL;
    node->next = NULL;
    return(node);
}

void	add_here_to_end(t_heredoc **lst, t_heredoc *var)
{
	t_heredoc	*last;
	
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

t_heredoc     *create_here_lst(t_minish *m_s, char *input)
{
	t_heredoc *hereNode;

	hereNode = NULL;
    add_here_to_end(&m_s->herelst, intHereLst(hereNode, input));
    return(m_s->herelst);
}

/*====================================================*/
/*=                    PRINT TEST                    =*/
/*====================================================*/

void	print_here_lst(t_heredoc *lst)
{
	t_heredoc *last;
	
	last = lst;
	if(last == NULL )
		printf("empty HERE DOCUMENT list\n");
	while(last != NULL)
	{
		printf("========== HERE STR ==============\n");
		printf("= token prev  : %p           \n", last->prev);
		printf("= token key   : %s          \n", last->str);
		printf("= token value : %s          \n", last->expstr);
		printf("= token next  : %p           \n", last->next);
		printf("===============================\n");
		printf("                 =\n");
		printf("                 =\n");
		last = last->next;
	}
}