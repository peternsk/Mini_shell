/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manage_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:19:10 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:19:12 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_manage_fds	*init_manage_fd(int copy_fd, int error, int is_open)
{
	t_manage_fds	*node;

	node = malloc_and_add(sizeof(t_manage_fds));
	if (!node)
		return (NULL);
	node->copy_fd = copy_fd;
	node->error = error;
	node->is_open = is_open;
	node->next = NULL;
	return (node);
}
