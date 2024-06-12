/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:27:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:27:24 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c_parent(int x)
{
	(void)x;
	write(1, "\n", 1);
	// rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	exit_here_doc(int x)
{
	(void)x;
	write(1, "\n", 1);
	// rl_reset_line_state();
	// rl_replace_line("", 0);
	exit(EXIT_FAILURE);
}

void	ctrl_quit_childs(int x)
{
	(void)x;
	exit(127);
}

void	ctrl_c_childs(int x)
{
	(void)x;
	exit(127);
}

void	manage_signal(int id)
{
	if (id == 0)
	{
		signal(SIGINT, ctrl_quit_childs);
		signal(SIGQUIT, ctrl_quit_childs);
	}
	else if (id == 3)
	{
		signal(SIGINT, exit_here_doc);
		signal(SIGQUIT, SIG_IGN);
	}
	if (id == -1)
	{
		signal(SIGINT, ctrl_c_parent);
		signal(SIGQUIT, SIG_IGN);
	}
}
