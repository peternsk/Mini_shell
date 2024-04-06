/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildRedlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:39:23 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/05 19:54:50 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redlts 	*setRed(t_redlts *redNode)
{
	redNode = malloc(sizeof(t_redlts));
	if(!redNode)
		return(0);
	redNode->prev = NULL;
	redNode->redtype = -1;
	redNode->filename = NULL;
	redNode->next = NULL;
	return(redNode);
}

void	add_redNode_to_end(t_redlts **lst, t_redlts *redNode)
{
	t_redlts *last;
	
	if(!lst)
		return;
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


// void 	ft_createRedLst(t_cmdlts *cmdNode, int nb_redTok)
void 	ft_createRedLst(t_cmdlts *cmdNode)
{
	t_redlts *redNode;

	redNode = NULL;
	// while(nb_redTok > 0)
	// {
    	add_cmdNode_to_end(&cmdNode->redlst, set_red(redNode));
	// 	nb_redTok--;
	// }
}

int		countNbRednode(t_token **lst)
{
	t_token *token;
	int	nb_redTok;

	token = *lst;
	nb_redTok = 0;
	while(token && token->type != pipe_)
	{
		if(token && (token->type == out_p_redir ||
		 token->type == in_p_redir || token->type == apnd_op_redir 
		 || token->type == here_doc))
			nb_redTok++;
		token = token->next;
	}
	return(nb_redTok);
}


void	ft_redBuilder(t_minish *m_s)
{
	int i;

	i = 0;
	t_redlts *redNode;

	redNode = 
	while(m_s->token_lst)
	{
		if(m_s->token_lst && (m_s->token_lst->type == out_p_redir || m_s->token_lst->type == in_p_redir 
		|| m_s->token_lst->type == apnd_op_redir || m_s->token_lst->type == here_doc))
		{
			ft_createRedLst(m_s->cmdLst->redlst);
			m_s->cmdLst->redlst
		}
		else if(curTok && curTok->type == pipe_)
		{
			curCmd->command[i] = NULL;
			i = 0;
			curCmd = curCmd->next;
		}
		curTok = curTok->next;
	}
	curCmd->command[i] = NULL;
}
