/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergnas <lvergnas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:26:45 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/12 14:24:07 by lvergnas         ###   ########.fr       */
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