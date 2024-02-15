/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:25:43 by petermalong       #+#    #+#             */
/*   Updated: 2022/12/06 13:52:47 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clr_node;

	if (!*lst || !del)
		return ;
	while (*lst != 0)
	{
		clr_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = clr_node;
	}
	(*lst) = 0;
}
