/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildCmdArr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:37:48 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/30 15:29:38 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		ft_countArrayspace(t_token **lst)
{
	t_token *last;
	int	arrSpc;

	last = *lst;
	arrSpc = 1;
	while(last && last->type != pipe_)
	{
		if(last->endToken == 1)
			arrSpc++;
		last = last->next;
	}
	return(arrSpc);
}

// char    *ft_statchValue(t_token **lst)
// {
//     t_token *last;
// 	char *combTok;

// 	last = *lst;
// 	combTok = NULL;
// 	while(last != NULL && last->type != pipe_ && last->endToken == 0 && last->setToCmd == FLAG_OFF)
// 	{
// 		if(combTok == NULL)
// 			combTok = ft_strdup(last->value);
// 		else
// 			combTok = ft_strjoin(combTok, last->value);
// 		last->setToCmd = FLAG_ON;
// 		last = last->next;
// 	}
// 	if(last->endToken == 1)
// 	{
// 		if(last->prev == NULL)
// 			combTok = ft_strdup(last->value);
// 		if(last->prev->endToken == 0)
// 			combTok = ft_strjoin(combTok, last->value);
// 		last->setToCmd = FLAG_ON;
// 	}
// 	last = *lst;
// 	printf("CMDlist argument : %s\n", combTok);
// 	return(combTok);
// }

char    *ft_setCmd(t_token **lst, t_minish *m_s)
{
	t_token *last;
	int i;

	last = *lst;
	i = 0;
	while(last != NULL)
	{
		while(last->type != pipe_)
		{
			m_s->cmdLst = ;
		}
	}
}

void	init_cmdlst(t_minish *m_s)
{
	
}

// char   **ft_builder(t_cmdlts *cmd, t_minish *m_s)
// {
// 	t_cmdlts *cur;
// 	int i;

// 	cur = cmd;
// 	i = 0;
// 	cur->arrLen = ft_countArrayspace(&m_s->token_lst);
// 	cur->command = (char **)malloc((sizeof(char *) * (cur->arrLen)) + 1);
// 	if(!cur->command)
// 		return(0);
// 	printf("combined token : %d\n", cur->arrLen);
// 	while(i < cur->arrLen)
// 	{
// 		cur->command[i] = ft_statchValue(&m_s->token_lst);
// 		printf("combined token : %s\n", cur->command[i]);
// 		i++;
// 	}
// 	return(cur->command);
// }