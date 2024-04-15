/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:50:26 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/12 21:25:50 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_garbage	*set_addy_node(t_garbage *node, void *value)
{
	node = malloc(sizeof(t_garbage));
	if(!node)
		return(0);
	node->prev = NULL;
	node->adresse = value;
	node->next = NULL;
	return(node);
}

void	add_node_to_end(t_garbage **lst, t_garbage *node)
{
	t_garbage *last;
	
	if(!lst)
		return;
	if(*lst == NULL)
	{
		*lst = node;
		node->next = NULL;
		return;	
	}
	last = *lst;
	while(last->next != NULL)
		last = last->next;
	last->next = node;
	node->prev = last;
}

void	*malloc_and_add(size_t size, void *var_to_malloc, t_garbage **gbLst)
{
	t_garbage *node;

	node = NULL;
	var_to_malloc = malloc(size);
	if(!var_to_malloc)
		return(0);
	add_node_to_end(gbLst, set_addy_node(node, var_to_malloc));
	return(var_to_malloc);
}