/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_change_std.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:31:12 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/22 23:33:20 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    is_change_std(t_files *files)
{
    if (files)
    {
        if (files->type == apnd_op_redir)
            ft_append(files);
        if (files->type == in_p_redir)
            change_stdint(files);
        if (files->type == out_p_redir)
            change_stdout(files);

    }
}