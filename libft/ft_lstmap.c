/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:52:17 by pnsaka            #+#    #+#             */
/*   Updated: 2022/12/06 13:56:12 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_f;
	t_list	*new_lst;
	void	*ssd;

	new_lst = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		ssd = ((*f)(lst->content));
		lst_f = ft_lstnew(ssd);
		if (!lst_f)
		{
			ft_lstclear(&new_lst, del);
			free(ssd);
		}
		ft_lstadd_back(&new_lst, lst_f);
		lst = lst->next;
	}
	return (new_lst);
}
