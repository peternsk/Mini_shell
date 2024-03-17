/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmdLst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:58:11 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/17 02:04:36 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdlts 	*set_cmdNode(t_cmdlts *cmd, t_minish *m_s)
{
	cmd = malloc(sizeof(t_cmdlts));
	if(!cmd)
		return(0);
	cmd->prev = NULL;
	cmd->arrLen = -1;
	cmd->index = m_s->index;
	m_s->index = m_s->index + 1;
	cmd->redlst = NULL;
	cmd->command = NULL;
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

t_cmdlts    *create_cmdLst(t_minish *m_s)
{
	t_cmdlts *cmd;
	int lstLen;

	cmd = NULL;
	lstLen = ft_nbrOfNode(&m_s->token_lst);
	m_s->index = 0;
	while(lstLen > 0)
	{
    	add_cmdNode_to_end(&m_s->cmdLst, set_cmdNode(cmd, m_s));
		lstLen--;
	}
    return(m_s->cmdLst);
}

void	print_cmdLst(t_cmdlts *lst)
{
	t_cmdlts *last;
	
	last = lst;
	if(last == NULL )
		printf("empty list\n");
	while(last != NULL)
	{
		printf("========== CMD LST ============\n");
		printf("= command prev  : %p           \n", last->prev);
		printf("= command id    : %d             \n", last->index);
		printf("= array len     : not set yet    \n");
		printf("= command array : not set yet    \n");
		printf("= redir list    : not set yet    \n");
		printf("= command next  : %p           \n", last->next);
		printf("===============================\n");
		printf("                 =\n");
		printf("                 =\n");
		last = last->next;
	}
}

