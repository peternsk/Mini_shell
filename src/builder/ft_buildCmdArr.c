/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildCmdArr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:37:48 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/29 13:00:22 by pnsaka           ###   ########.fr       */
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

char    *ft_statchValue(t_token **lst)
{
    t_token *last;
	char *combTok;

	last = *lst;
	combTok = NULL;
	while(last != NULL && last->type != pipe_ && last->endToken == 0 && last->setToCmd == FLAG_OFF)
	{
		if(combTok == NULL)
			combTok = ft_strdup(last->value);
		else
			combTok = ft_strjoin(combTok, last->value);
		last->setToCmd = FLAG_ON;
		last = last->next;
	}
	if(last->endToken == 1)
	{
		if(last->prev == NULL)
			combTok = ft_strdup(last->value);
		if(last->prev->endToken == 0)
			combTok = ft_strjoin(combTok, last->value);
		last->setToCmd = FLAG_ON;
	}
	printf("CMDlist argument : %s\n", combTok);
	return(combTok);
}

char   **ft_builder(t_cmdlts *cmd, t_minish *m_s)
{
    int len;
	int i;
	t_cmdlts *cur;

	i = 0;
	len = ft_countArrayspace(&m_s->token_lst);
	cur = cmd;
	cur->command = (char **)malloc((sizeof(char *) * (len )) + 1);
	if(!cur->command)
		return(0);
	cur->arrLen = len;
	printf("combined token : %d\n", len);
	while(i < len)
	{
		cur->command[i] = ft_statchValue(&m_s->token_lst);
		printf("combined token : %s\n", cur->command[i]);
		i++;
	}
	return(cur->command);
}