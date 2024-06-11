#include "minishell.h"

t_cmdlts 	*set_cmdNode(t_cmdlts *cmd, t_minish *m_s)
{
	cmd = malloc_and_add(sizeof(t_cmdlts));
	if(!cmd)
		return(0);
	cmd->prev = NULL;
	cmd->arrLen = -1;
	cmd->index = m_s->index;
	m_s->index = m_s->index + 1;
	cmd->command = (char **)malloc_and_add((sizeof(char *) * 150) + 1);
	if(!cmd->command)
		return(0);
	cmd->redlst = NULL;
	cmd->next = NULL;
	return(cmd);
}

void	add_cmdNode_to_end(t_cmdlts **lst, t_cmdlts *cmd)
{
	t_cmdlts *last;
	
	if(!lst)
		return;
	if(*lst == NULL)
	{
		*lst = cmd;
		cmd->next = NULL;
		return;	
	}
	last = *lst;
	while(last->next != NULL)
		last = last->next;
	last->next = cmd;
	cmd->prev = last;
}

int		ft_nbrOfNode(t_token **lst)
{
	t_token *last;
	int	nodeNeeded;

	last = *lst;
	nodeNeeded = 1;
	while(last != NULL)
	{
		if(last->type == pipe_)
			nodeNeeded++;
		last = last->next;
	}
	return(nodeNeeded);
}


void	printArray(char **arr)
{
	int i = 0;
	// printf("========== command ============\n");
	while(arr[i])
	{
		// printf("%s\n", arr[i]);
		// printf("_______________________________\n");
		i++;
	}
	// printf("===============================\n");
}

void	print_cmdLst(t_cmdlts **lst)
{
	t_cmdlts *last;
	int i;
	
	last = *lst;
	i = 0;
	if(last == NULL)
		// printf("= empty list\n");
	while(last != NULL)
	{
		// printf("============= CMD =============\n");
		// printf("= " GRN "command prev  : %p" RESET " \n", last->prev);
		// printf("= command id    : "YEL"%d" RESET " \n", last->index);
		while(last->command[i] != NULL)
		{
			// printf("= argument[%d]   :" BLU " %s" RESET "         \n", i, last->command[i]);
			i++;
		}
		// printf("= argument[%d]   :" BLU " %s" RESET "         \n", i, last->command[i]);
		// printf("= " GRN "command next  : %p" RESET " \n", last->next);
		print_redLst(&last->redlst);
		// printf("===============================\n");
		// printf("                 =\n");
		// printf("                 =\n");
		i = 0;
		last = last->next;
	}
}

void 	ft_createCmdLst(t_minish *m_s)
{
	t_cmdlts *cmd;
	int nbOfNnode;

	cmd = NULL;
	m_s->index = 0;
	nbOfNnode = ft_nbrOfNode(&m_s->token_lst);
	while(nbOfNnode > 0)
	{
    	add_cmdNode_to_end(&m_s->cmdLst, set_cmdNode(cmd, m_s));
		nbOfNnode--;
	}
}
