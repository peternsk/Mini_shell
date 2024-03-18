/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildCmdArr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:37:48 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/18 13:28:10 by pnsaka           ###   ########.fr       */
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
	return(combTok);
}

void    ft_builder(t_cmdlts *cmd, t_token **tokLst)
{
    int len;
	int i;
	t_token *tok;

	 i = 0;
	tok = *tokLst;
	len = ft_countArrayspace(&tok);
	cmd->command = (char **)malloc((sizeof(char *) * (len )) + 1);
	if(!cmd->command)
		return;
	cmd->arrLen = len;
	printf("combined token : %d\n", len);
	while(i < len)
	{
		cmd->command[i] = ft_statchValue(&tok);
		printf("combined token : %s\n", cmd->command[i]);
		i++;
	}
}