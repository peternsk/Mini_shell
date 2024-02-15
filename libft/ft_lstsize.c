/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:52:06 by pnsaka            #+#    #+#             */
/*   Updated: 2022/12/06 14:33:15 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstlen;

	lstlen = 0;
	if (!lst)
		return (0);
	while (lst != 0)
	{
		lst = lst->next;
		lstlen++;
	}
	return (lstlen);
}
