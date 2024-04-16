/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildRedlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:39:23 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/15 20:41:03 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redlts 	*setRed(char *redtype, char *filename)
{
	t_redlts *redNode;
	
	redNode = malloc_and_add(sizeof(t_redlts));
	if(!redNode)
		return(0);
	redNode->prev = NULL;
	redNode->redtype = redtype;
	redNode->filename = filename;
	redNode->next = NULL;
	return(redNode);
}

void	add_redNode_to_end(t_redlts **lst, t_redlts *redNode)
{
	t_redlts *last;
	
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

void	print_redLst(t_redlts **lst)
{
	t_redlts *last;
	
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
		printf("= RED->TYPE      :" RED " %s" RESET "         \n", last->redtype);
		printf("= RED->ARG       :" GRN " %s" RESET "         \n", last->filename);
		last = last->next;
	}
	printf("-------------------------------\n");
}