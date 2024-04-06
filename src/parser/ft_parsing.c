/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:21:58 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/05 23:27:07 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	begin_setEnvVar(void)
{
	printf("                 =\n");
	printf("                 =\n");
	printf("===============================\n");
	printf("=       Setting env var       =\n");
	printf("===============================\n");
	printf("                 =\n");
	printf("                 =\n");
}

void	begin_parsing(void)
{
	printf("                 =\n");
	printf("                 =\n");
	printf("===============================\n");
	printf("=             PARSER          =\n");
	printf("===============================\n");
	printf("                 =\n");
	printf("                 =\n");
}

void	begin_lexing(void)
{
	printf("===============================\n");
	printf("=              LEXER          =\n");
	printf("===============================\n");
	printf("                 =\n");
	printf("                 =\n");
}

bool	prs_ast_pipe(t_token **lst)
{
	t_token *current;

	current = *lst;
	while(current != NULL)
	{
		if((current->type == pipe_ && (current->prev == NULL ||  current->next == NULL)) || current->type == dbl_pipe_)
			return(false);
		current = current->next;
	}
	return(true);
}

bool	prs_ast_redir(t_token **lst)
{
	t_token *current;

	current = *lst;
	while(current != NULL)
	{
		if((current->type >= out_p_redir && current->type <= here_doc ) && (current->prev == NULL &&  current->next == NULL))
			return(false);
		if((current->type >= out_p_redir && current->type <= here_doc ) && (current->next == NULL))
			return(false);
		current = current->next;
	}
	return(true);
}


bool	prs_ast_dlb_meta(t_token **lst)
{
	t_token *current;

	current = *lst;
	while(current != NULL && current->next != NULL)
	{
		if((current->type >= out_p_redir && current->type <= dbl_pipe_) && (current->next->type >= out_p_redir && current->next->type <= dbl_pipe_))
			return(false);
		current = current->next;
	}
	return(true);
	
}

void    ft_lexer(t_token **lst)
{
    if(prs_ast_pipe(lst) == false || prs_ast_dlb_meta(lst) == false || prs_ast_redir(lst) == false)
	{
		exit_status = 0;
		exit_status = exit_status + 2;
		printf("===============================\n");
		printf("=      bash: syntax error     =\n");
		printf("===============================\n");
		printf("                =\n");
		printf("===============================\n");
		printf("=             $? : %d          =\n", exit_status);
		printf("===============================\n");
		exit(0);
		
	}
	else
	{
		printf("===============================\n");
		printf("=      command parse ok       =\n");
		printf("===============================\n");
		printf("                =\n");
		printf("===============================\n");
		printf("=             $? : %d          =\n", exit_status);
		printf("===============================\n");	
	}
}