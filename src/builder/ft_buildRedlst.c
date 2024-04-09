/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildRedlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:39:23 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/09 12:15:52 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_redlts 	*setRed(t_redlts *redNode, char *redtype, char *filename)
// {
// 	redNode = malloc(sizeof(t_redlts));
// 	if(!redNode)
// 		return(0);
// 	redNode->prev = NULL;
// 	redNode->redtype = redtype;
// 	redNode->filename = filename;
// 	redNode->next = NULL;
// 	return(redNode);
// }

// void	add_redNode_to_end(t_redlts **lst, t_redlts *redNode)
// {
// 	t_redlts *last;
	
// 	if(!*lst)
// 		return;
// 	if(*lst == NULL)
// 	{
// 		*lst = redNode;
// 		redNode->next = NULL;
// 		return;	
// 	}
// 	last = *lst;
// 	while(last->next != NULL)
// 		last = last->next;
// 	last->next = redNode;
// 	redNode->prev = last;
// }


// void	ft_createRedLst(t_redlts *redlst, char *redtype, char *filename)
// {
// 	t_redlts *redNode;

// 	redNode = NULL;
//     add_redNode_to_end(&redlst, setRed(redNode, redtype, filename));
// }

// int		countNbRednode(t_token **lst)
// {
// 	t_token *token;
// 	int	nb_redTok;

// 	token = *lst;
// 	nb_redTok = 0;
// 	while(token && token->type != pipe_)
// 	{
// 		if(token && (token->type >= out_p_redir && token->type <= in_p_redir))
// 			nb_redTok++;
// 		token = token->next;
// 	}
// 	return(nb_redTok);
// }

// void	print_redLst(t_redlts **lst)
// {
// 	t_redlts *last;
	
// 	last = *lst;
// 	if(last == NULL)
// 		printf("= empty list\n");
// 	while(last != NULL)
// 	{
// 		printf("===========  RED NODE =========\n");
// 		printf("= command prev  : %p           \n", last->prev);
// 		printf("= redtype       :" BLU " %s" RESET "         \n", last->redtype);
// 		printf("= filename       :" GRN " %s" RESET "         \n", last->filename);
// 		printf("= command next  : %p           \n", last->next);
// 		printf("===============================\n");
// 		printf("                 =\n");
// 		printf("                 =\n");
// 		last = last->next;
// 	}
// }