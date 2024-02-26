/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/26 11:32:40 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char **av)
{
	t_minish *minish;
	(void)av;

	if(ac > 0)
	{
		ft_ascii_font();
		minish = crt_str_ms();
		minish->flags = crt_str_flag();
		minish->input = readline(INPUT);
		printf("the command is : %s\n", minish->input);
		tokenizer(minish);
	}
	else
		printf("arg missing !!\n");
}