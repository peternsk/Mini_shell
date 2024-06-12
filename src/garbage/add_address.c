/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:20:48 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:20:50 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_garbage	*get_head(void)
{
	static struct s_garbage	garb_coll = {0, 0};

	return (&garb_coll);
}

void	*malloc_and_add(size_t size)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (!node)
		return (0);
	node->adresse = malloc(size);
	if (!node->adresse)
	{
		free(node);
		return (0);
	}
	node->next = get_head()->next;
	get_head()->next = node;
	return (node->adresse);
}

void	add_garbage(void *adresse)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (!node)
		return ;
	node->adresse = adresse;
	node->next = get_head()->next;
	get_head()->next = node;
}

void	all_free(void)
{
	t_garbage	*gc_ptr;
	t_garbage	*tmp;

	gc_ptr = get_head()->next;
	while (gc_ptr)
	{
		if (gc_ptr->adresse)
		{
			free(gc_ptr->adresse);
			gc_ptr->adresse = NULL;
		}
		tmp = gc_ptr;
		gc_ptr = gc_ptr->next;
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	get_head()->next = NULL;
}

void	add_garbage_arr(char **arr)
{
	int	i;

	i = 0;
	add_garbage(arr);
	while (arr[i])
	{
		add_garbage(arr[i]);
		i++;
	}
}
