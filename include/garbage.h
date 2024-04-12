/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:26:45 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/12 12:50:47 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
#define GARBAGE_H

/*====================================================*/
/*=                     STRUCTURE                    =*/
/*====================================================*/
typedef struct s_garbage
{
	struct s_garbage *prev;
	void	*adresse;
	struct s_garbage *next;
} t_garbage;

/*====================================================*/
/*=                     FUNCTIONS                    =*/
/*====================================================*/

/*--- ADDING NODE TO THE GARBAGE LINKED LIST ---*/

t_garbage	*set_add_node(t_garbage *node, void *value);
void		add_node_to_end(t_garbage **lst, t_garbage *node);
void		*malloc_and_add(size_t size, void *var_to_malloc, t_garbage **gbLst);

/*--- DELETING NODE TO THE GARBAGE LINKED LIST ---*/

#endif