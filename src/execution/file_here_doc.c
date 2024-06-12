/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:18:08 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/12 09:20:43 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_expand(t_cmd *now_shine)
{
	manage_signal(3);
	while (now_shine != NULL)
	{
		run_here_redlst(now_shine->glob, &now_shine->files);
		herelist_exp(&now_shine->glob->herelst, &now_shine->glob->env_varlst,
			now_shine->glob);
		now_shine = now_shine->next;
	}
}

int	expan_here_doc(t_cmd *current)
{
	t_cmd	*now_shine;
	pid_t	pid_childs;
	int		state;

	now_shine = current;
	if (is_there_here_doc(now_shine) > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		pid_childs = fork();
		if (pid_childs == 0)
		{
			on_expand(now_shine);
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(pid_childs, &state, 0);
			manage_signal(-1);
			current->exit_here_doc = state;
		}
	}
	return (0);
}
