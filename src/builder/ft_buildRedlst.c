
#include "minishell.h"

t_files		*setRed(char *redtype, char *filename, t_minish *m_s)
{
	t_files *redNode;
	
	redNode = malloc_and_add(sizeof(t_files));
	if (!redNode)
        return (NULL);
    redNode->name = filename;
    redNode->index = 0;
    redNode->made = 0;
    redNode->error = 0;
    redNode->index_out = 0;
    redNode->put_last = 0;
    redNode->type = type_cmds(redtype);
	if(redNode->type == here_doc)
	{
		redNode->hereID = m_s->here_id;
		m_s->here_id = m_s->here_id + 1;
		printf("we are look%d\n", redNode->hereID);
	}
    redNode->next = NULL;
    redNode->manage_fd = -1;
    return (redNode);
}

void	add_redNode_to_end(t_files **lst, t_files *redNode)
{
	t_files *last;
	
	if(*lst == NULL)
	{
		*lst = redNode;
		redNode->next = NULL;
		return;	
	}
	last = *lst;
	while(last->next != NULL)
		last = last->next;
	last->next = redNode;
	redNode->prev = last;
}


int		countNbRednode(t_token **lst)
{
	t_token *token;
	int	nb_redTok;

	token = *lst;
	nb_redTok = 0;
	while(token && token->type != pipe_)
	{
		if(token && (token->type >= out_p_redir && token->type <= in_p_redir))
			nb_redTok++;
		token = token->next;
	}
	return(nb_redTok);
}

void	print_redLst(t_files **lst)
{
	t_files *last;
	
	last = *lst;
	if(last == NULL)
	{	
		printf("-------------------------------\n");
		printf("- " RED "EMPTY RED LIST  " RESET "  \n");
		printf("-------------------------------\n");
	}
	while(last != NULL)
	{
		printf("-------------------------------\n");
		// printf("= RED->TYPE      :" RED " %s" RESET "         \n", last->redtype);
		printf("= RED->ARG       :" GRN " %d" RESET "         \n", last->type);
		printf("= RED->ARG       :" GRN " %s" RESET "         \n", last->name);
		last = last->next;
	}
	printf("-------------------------------\n");
}