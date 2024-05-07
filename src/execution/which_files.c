/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:29:51 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/07 19:05:54 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    which_files(t_cmd *current)
{
   if (current->files)
    {
        t_files *files = current->files;
        while (files != NULL)
        {            
            ft_append(files);
            change_stdint(files);
            if (is_files_valide(current) == 0)
                change_stdout(files);
            files = files->next;
            
        }
    }
}