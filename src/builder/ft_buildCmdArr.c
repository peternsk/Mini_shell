/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildCmdArr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:37:48 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/05 23:00:33 by pnsaka           ###   ########.fr       */
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
		if(last->type == argument && last->endToken == 1 && last->setToCmd == FLAG_OFF)
			arrSpc++;
		last = last->next;
	}
	return(arrSpc);
}

void	ft_cmdBuilder(t_token **toklst, t_cmdlts **cmdlst)
{
	t_token *curTok;
	t_cmdlts *curCmd;
	int i;
	
	curTok = *toklst;
	curCmd = *cmdlst;
	i = 0;
	while(curTok)
	{
		if(curTok && (curTok->type == command || curTok->type == argument || 
		curTok->type == sgl_quote_arg || curTok->type == dbl_quote_arg))
		{
			curCmd->command[i] = ft_strdup(curTok->value);
			i++;
		}
		else if(curTok && curTok->type == pipe_)
		{
			curCmd->command[i] = NULL;
			i = 0;
			curCmd = curCmd->next;
		}
		curTok = curTok->next;
	}
	curCmd->command[i] = NULL;
}
