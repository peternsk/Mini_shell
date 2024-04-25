/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:40:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/22 23:40:36 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int change_stdint(t_files *file)
{
    int fd;

    if (file)
    {
        if (file->name)
        {
            if (file->name)
            {
                fd = open(file->name, O_RDONLY);
                if (fd > 0)
                {
                    dup2(fd, 0);
                    return (1);
                }
            }
            return (-1);
        }    
    }
    return (-1);
}