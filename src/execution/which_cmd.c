/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:29:51 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/22 23:33:49 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    which_cmd(t_cmd *current)
{
    if (current->files)
        is_change_std(current->files);
    if (current->type == out_p_redir)
    {
        // we make de les here and we look at the > redirection
        // exit();
    }
    if (current->type == 8)
    {
        // we make de commande and we look at the > redirection
        // exit();
    }
}