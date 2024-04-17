/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:26:45 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/17 09:13:59 by pnsaka           ###   ########.fr       */
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

t_garbage 	*get_head(void);
void		*malloc_and_add(size_t size);
void		add_garbage(void *adresse);

/*--- DELETING NODE TO THE GARBAGE LINKED LIST ---*/
void		all_free(void);


/*--- PRINTING THE GARBAGE LINKED LIST ---*/

void		print_garbage_collector();

#endif