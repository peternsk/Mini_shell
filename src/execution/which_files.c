/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:29:51 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/05 14:33:55 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    which_files(t_cmd *current)
{
    if (current->files)
    {
        is_change_std(current);
    }
    // if (current->files)
    // {
    //     if (current->files->type == here_doc)
    //     {
    //         // we make de commande and we look at the > redirection
    //         // exit();
    //     }
    // }
}