/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildCmdArr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:37:48 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/04 00:14:55 by pnsaka           ###   ########.fr       */
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


// char	*set_arg_to_arr(t_token **toklst)
// {
// 	t_token *cur;
// 	char *cmd;
	
// 	cur = *toklst;
// 	cmd = NULL;
// 	if(cur != NULL && cur->endToken == 1 && cur->type == argument && cur->setToCmd == FLAG_OFF)
// 	{
// 		cmd = ft_strdup(cur->value);
// 		cur->setToCmd = FLAG_ON;
// 	}
// 	while(cur != NULL && cur->endToken == 0 && cur->type == argument && cur->setToCmd == FLAG_OFF)
// 	{
// 		cmd = ft_strjoin(cmd, cur->value);
// 		cur->setToCmd = FLAG_ON;
// 	}
// 	printf("== cmd : %s\n", cmd);
// 	return(cmd);
// }

// char	**fill_cmd_arr(t_token **toklst)
// {
// 	t_token *cur;
// 	char **cmdarr;
// 	int arrlen;
// 	int i;

// 	cur = *toklst;
// 	arrlen = ft_countArrayspace(toklst);
// 	cmdarr = (char **)malloc((sizeof(char *) * arrlen) + 1);
// 	i = 0;
// 	while(cur && cur->type != pipe_)
// 	{
// 		cmdarr[i] = set_arg_to_arr(toklst);
// 		i++;
// 	}
// 	return(cmdarr);
// }

