/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:26:45 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/29 18:30:28 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
#define GARBAGE_H

typedef struct s_garbage
{
	struct s_garbage *prev;
	void	*adresse;
	struct s_garbage *next;
} t_garbage;


#endif