/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:37:37 by petermalong       #+#    #+#             */
/*   Updated: 2022/12/06 14:37:00 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	last_node = *lst;
	if (!lst || !new)
		return ;
	if ((*lst) == 0)
		*lst = new;
	else
	{
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
	}
}
