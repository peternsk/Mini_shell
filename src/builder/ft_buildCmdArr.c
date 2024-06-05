#include "minishell.h"

int	ft_countArrayspace(t_token **lst)
{
	t_token	*last;
	int		arrSpc;

	last = *lst;
	arrSpc = 1;
	while (last && last->type != pipe_)
	{
		if (last->type == argument && last->end_token == 1
			&& last->set_to_cmd == FLAG_OFF)
			arrSpc++;
		last = last->next;
	}
	return (arrSpc);
}

void	ft_cmd_builder(t_minish *m_s, t_token **toklst, t_cmdlts **comd_lst)
{
	t_token		*cur_tok;
	t_cmdlts	*cur_cmd;
	int			i;

	cur_tok = *toklst;
	cur_cmd = *comd_lst;
	i = -1;
	while (cur_tok)
	{
		if (cur_tok && (cur_tok->type >= command && cur_tok->type <= DQA))
		{
			cur_cmd->command[++i] = ft_strdup(cur_tok->value);
			add_garbage(cur_cmd->command[i]);
		}
		else if (cur_tok && (cur_tok->type >= OPR && cur_tok->type <= here_doc))
			add_red_node_to_end(&cur_cmd->redlst, set_red(cur_tok->value,
					cur_tok->next->value, m_s));
		else if (cur_tok && cur_tok->type == pipe_)
		{
			cur_cmd->command[++i] = NULL;
			i = -1;
			cur_cmd = cur_cmd->next;
		}
		cur_tok = cur_tok->next;
	}
	cur_cmd->command[++i] = NULL;
}
