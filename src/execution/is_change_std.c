/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_change_std.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:31:12 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/05 21:17:16 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    is_change_std(t_cmd *current)
{
    if (current->files)
    {
        t_files *files = current->files;
        while (files != NULL)
        {            
            ft_append(files);
            current->is_file_on = change_stdint(files);
            current->is_file_on = change_stdout(files);
            files = files->next;
        }

    }
}