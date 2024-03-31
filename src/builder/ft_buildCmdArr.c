/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildCmdArr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:37:48 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/31 14:04:17 by pnsaka           ###   ########.fr       */
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


char	*set_arg_to_arr(t_token **toklst)
{
	t_token *cur;
	char *cmd;
	
	cur = *toklst;
	if(cur != NULL && cur->endToken == 1 && cur->type == argument && cur->setToCmd == FLAG_OFF)
	{
		cmd = ft_strdup(cur->value);
		cur->setToCmd = FLAG_ON;
	}
	while(cur != NULL && cur->endToken == 0 && cur->type == argument && cur->setToCmd == FLAG_OFF)
	{
		
	}
	return(cmd);
}

char	**fill_cmd_arr(t_token **toklst)
{
	t_token *cur;
	char **cmdarr;
	int arrlen;
	int i;

	cur = *toklst;
	arrlen = ft_countArrayspace(toklst);
	cmdarr = (char **)malloc((sizeof(char *) * arrlen) + 1);
	i = 0;
	while(cur && cur->type != pipe_)
	{
		cmdarr[i] = 
		i++;
	}
	return(cmdarr);
}

void	ft_builder(t_token **tokLst ,t_cmdlts *cmd, t_minish *m_s)
{
	t_token *cur;

	cur = *tokLst;
	while(cur != NULL)
	{
		while(cur != NULL || cur->type != pipe_)
		{
			create_cmd(m_s);
		}
		//cur = function qui voyage jusqu'a la valeur unset
	}
}
