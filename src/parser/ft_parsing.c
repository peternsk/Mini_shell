#include "minishell.h"

void	begin_set_env_var(void)
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
	t_token	*current;

	current = *lst;
	while (current != NULL)
	{
		if ((current->type == pipe_ && (current->prev == NULL
					|| current->next == NULL)) || current->type == DBLP)
		{
			printf("prs_ast_pipe\n");
			return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	prs_ast_redir(t_token **lst)
{
	t_token	*current;

	current = *lst;
	// printf("IN HERE\n");
	while(current != NULL)
	{
		if ((current->type >= OPR && current->type <= here_doc)
			&& (current->prev == NULL && current->next == NULL))
		{
			printf("prs_ast_redir\n");
			return (false);
		}
		if ((current->type >= OPR && current->type <= here_doc)
			&& (current->next == NULL))
		{
			printf("prs_ast_redir\n");
			return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	prs_ast_dlb_meta(t_token **lst)
{
	t_token	*cur;

	cur = *lst;
	while (cur != NULL)
	{
		if ((cur && (cur->type >= OPR && cur->type <= DBLE)) && (cur->next
				&& (cur->next->type == here_doc)))
			cur = cur->next;
		if ((cur && (cur->type >= OPR && cur->type <= DBLE)) && (cur->next
				&& (cur->next->type == APOR || (cur->next->type >= pipe_
						&& cur->next->type <= DBLE))))
			return (false);
		else if ((cur->type >= OPR && cur->type <= DBLE) && (cur->prev == NULL)
			&& (cur->next == NULL))
			return (false);
		cur = cur->next;
	}
	return (true);
}

bool	ft_lexer(t_token **lst)
{
	if (prs_ast_pipe(lst) == false || prs_ast_dlb_meta(lst) == false
		|| prs_ast_redir(lst) == false)
	{
		g_exit_status = 0;
		g_exit_status = g_exit_status + 2;
		perror("bash: syntax error near unexpected token");
		return (false);
	}
	return (true);
}
