#include "minishell.h"

void	begin_setEnvVar(void)
{
	// printf("                 =\n");
	// printf("                 =\n");
	// printf("===============================\n");
	// printf("=       Setting env var       =\n");
	// printf("===============================\n");
	// printf("                 =\n");
	// printf("                 =\n");
}

void	begin_parsing(void)
{
	// printf("                 =\n");
	// printf("                 =\n");
	// printf("===============================\n");
	// printf("=             PARSER          =\n");
	// printf("===============================\n");
	// printf("                 =\n");
	// printf("                 =\n");
}

void	begin_lexing(void)
{
	// printf("===============================\n");
	// printf("=              LEXER          =\n");
	// printf("===============================\n");
	// printf("                 =\n");
	// printf("                 =\n");
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
	// printf("IN HERE\n");
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
	while(current != NULL)
	{
		if(current)
		{
			if(current->type >= out_p_redir && current->type <= dbl_et)
			{
				if(current->next && (current->next->type >= apnd_op_redir && current->next->type <= dbl_et))
				return(false);
			}
		}
		else if((current->type >= out_p_redir && current->type <= dbl_et) && (current->prev == NULL) && (current->next == NULL))
			return(false);
		current = current->next;
	
	}
	return(true);
}

bool    ft_lexer(t_token **lst)
{
    if(prs_ast_pipe(lst) == false || prs_ast_dlb_meta(lst) == false || prs_ast_redir(lst) == false)
	{
		exit_status = 0;
		exit_status = exit_status + 2;
		perror("bash: syntax error near unexpected token");
		return(false);
	}
	return(true);
}