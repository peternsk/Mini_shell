
#include "minishell.h"

int	ft_count_arr_spc(t_token **lst)
{
	t_token	*last;
	int		arr_spc;

	last = *lst;
	arr_spc = 1;
	while (last && last->type != pipe_)
	{
		if (last->type == argument && last->end_token == 1
			&& last->set_to_cmd == FLAG_OFF)
			arr_spc++;
		last = last->next;
	}
	return (arr_spc);
}

void	ft_cmd_builder(t_minish *m_s, t_token **toklst, t_cmdlts **comd_lst)
{
	t_token		*c_t;
	t_cmdlts	*c_cm;
	int			i;

	c_t = *toklst;
	c_cm = *comd_lst;
	i = -1;
	while (c_t)
	{
		if(c_t && c_t->prev && (c_t->type >= command && c_t->type <= DQA) &&(c_t->prev->type >= OPR && c_t->prev->type <= APOR))
            c_t->type = _file;
		if (c_t && (c_t->type >= command && c_t->type <= DQA))
		{
			c_cm->command[++i] = ft_strdup(c_t->value);
			add_garbage(c_cm->command[i]);
		}
		else if (c_t && (c_t->type >= OPR && c_t->type <= here_doc))
			rd_end(&c_cm->redlst, set_red(c_t->value, c_t->next->value, m_s));
		else if (c_t && c_t->type == pipe_)
		{
			c_cm->command[++i] = NULL;
			i = -1;
			c_cm = c_cm->next;
		}
		c_t = c_t->next;
	}
	c_cm->command[++i] = NULL;
}
