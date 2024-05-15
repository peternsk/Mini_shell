/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildCmdArr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:37:48 by pnsaka            #+#    #+#             */
/*   Updated: 2024/05/14 10:23:57 by pnsaka           ###   ########.fr       */
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

void	ft_cmdBuilder(t_minish *m_s, t_token **toklst, t_cmdlts **cmdlst)
{
	t_token *curTok;
	t_cmdlts *curCmd;
	int i;
	
	curTok = *toklst;
	curCmd = *cmdlst;
	i = -1;
	while(curTok)
	{
		if(curTok && (curTok->type >= command && curTok->type <= dbl_quote_arg))
		{
			curCmd->command[++i] = ft_strdup(curTok->value);
			add_garbage(curCmd->command[i]);
		}
		else if(curTok && (curTok->type >= out_p_redir && curTok->type <= here_doc))
			add_redNode_to_end(&curCmd->redlst, setRed(curTok->value, curTok->next->value, m_s));
		else if(curTok && curTok->type == pipe_)
		{
			curCmd->command[++i] = NULL;
			i = -1;
			curCmd = curCmd->next;
		}
		curTok = curTok->next;
	}
	// run_here_redlst(m_s, &curCmd->redlst);
	// herelist_exp(&m_s->herelst, &m_s->envVarlst, m_s);
	// print_here_lst(m_s->herelst);
	curCmd->command[++i] = NULL;
}
