/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:20:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/23 11:35:29 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    wait_childs(t_cmd *cmds)
{
    t_cmd *curr;
    int code;

    curr = NULL;
    if (cmds)
    {
        curr = cmds;
        while (curr != NULL)
        {
            waitpid(curr->id, &code, 0);
            curr = curr->next;
        }
        exit_status = get_code(code);
    }
}
int	get_code(int exit_code)
{
	if (WIFEXITED(exit_code))
		return ((unsigned char)WEXITSTATUS(exit_code));
	else if (WIFSIGNALED(exit_code))
		return((unsigned char)(128 + WTERMSIG(exit_code)));
	return ((unsigned char)exit_code);
}
