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
	curCmd->command[++i] = NULL;
}
