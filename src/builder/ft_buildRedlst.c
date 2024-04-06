/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildRedlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:39:23 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/06 00:19:31 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redlts 	*setRed(t_redlts *redNode, int redtype, char *filename)
{
	redNode = malloc(sizeof(t_redlts));
	if(!redNode)
		return(0);
	redNode->prev = NULL;
	redNode->redtype = redtype;
	redNode->filename = filename;
	redNode->next = NULL;
	return(redNode);
}

void	add_redNode_to_end(t_redlts *lst, t_redlts *redNode)
{
	t_redlts *last;
	
	if(!lst)
		return;
	if(lst == NULL)
	{
		lst = redNode;
		redNode->next = NULL;
		return;	
	}
	last = lst;
	while(last->next != NULL)
		last = last->next;
	last->next = redNode;
	redNode->prev = last;
}


void	ft_createRedLst(t_redlts *redlst, int redtype, char *filename)
{
	t_redlts *redNode;

	redNode = NULL;
    add_redNode_to_end(redlst, setRed(redNode, redtype, filename));
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


void	ft_redBuilder(t_token **toklst, t_cmdlts **cmdlst)
{
	t_token *curTok;
	t_cmdlts *curCmd;
	int i;
	
	curTok = *toklst;
	curCmd = *cmdlst;
	i = 0;
	while(curTok)
	{
		if(curTok && (curTok->type == out_p_redir || curTok->type == in_p_redir || 
		curTok->type == apnd_op_redir || curTok->type == here_doc))
		{
			ft_createRedLst(curCmd->redlst, curTok->type, curTok->next->value);
			curTok = curTok->next; 
		}
		else if(curTok && curTok->type == pipe_)
		{
			curCmd = curCmd->next;
		}
		curTok = curTok->next;
	}
}
