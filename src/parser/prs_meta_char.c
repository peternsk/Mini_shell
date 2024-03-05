/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_meta_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:21:58 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/04 19:07:48 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	begin_parsing(void)
{
	printf("                 =\n");
	printf("                 =\n");
	printf("===============================\n");
	printf("=            PARSER           =\n");
	printf("===============================\n");
	printf("                 =\n");
	printf("                 =\n");
}

void	prs_ast_pipe(t_token **lst)
{
	t_token *current;

	current = *lst;
	while(current->next != NULL)
	{
		if (current->type == dbl_pipe_)
		{
			printf("minishell : this program do not handle `%s' \n", current->value);
			return;
		}
		else if(current->type == pipe_ && (current->prev == NULL ||  current->next == NULL))
		{
			printf("bash: syntax error near unexpected token `%s' \n", current->value);
			return;
		}
		current = current->next;
	}
	printf("***bash: syntax all good so far***\n");
}
