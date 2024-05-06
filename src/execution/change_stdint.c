/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:40:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/05 21:25:09 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int change_stdint(t_files *file)
{
    int fd;
    int old_fd;
    if (file)
    {
        if (file->name)
        {
            if (file->name && file->type == in_p_redir)
            {
                fd = open(file->name, O_RDONLY);
                if (fd > 0)
                {
                    old_fd = dup(0);               
                    dup2(fd, 0);
                    close(fd);
                    dup2(old_fd, 0);
                    close(old_fd);
                    return (0);
                }
            }
            return (perror(file->name), -1);
        }    
    }
    return (perror(file->name), -1);
}