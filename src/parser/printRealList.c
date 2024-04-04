/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printRealList.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:18:23 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/03 20:28:40 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *rightType(int type)
{
    char *str;
    
    if(type == 0)
        str = ft_strdup("CMG");
    if(type == 1)
        str = ft_strdup("ARG");
    if(type == 2)
        str = ft_strdup("SGL_Q");
    if(type == 3)
        str = ft_strdup("DBL_Q");
    if(type == 4)
        str = ft_strdup("OUT_RED");
    if(type == 5)
        str = ft_strdup("IN_RED");
    if(type == 6)
        str = ft_strdup("APND");
    if(type == 7)
        str = ft_strdup("HEREDOC");
    if(type == 8)
        str = ft_strdup("PIPE");
    if(type == 9)
        str = ft_strdup("DBL_PIPE");
    if(type == 10)
        str = ft_strdup("DELIMITER");
    if(type == 11)
        str = ft_strdup("FILE");
    return(str);
}

void	printRealList(t_token *lst)
{
	t_token *last;
	
	last = lst;
	if(last == NULL )
		printf("empty list\n");
	while(last != NULL)
	{
		printf("========== CMDLST =============\n");
		printf("= token prev  : %p           \n", last->prev);
		printf("= token id    : %d             \n", last->token_id);
		printf("= token value : %s          \n", last->value);
		printf("= token len   : %zu          \n", ft_strlen(last->value));
		printf("= token type  : %s          \n", rightType(last->type));
		printf("= token end   : %d          \n", last->endToken);
		printf("= token mrg   : %d          \n", last->to_merge);
		printf("= token next  : %p           \n", last->next);
		printf("===============================\n");
		printf("                 =\n");
		printf("                 =\n");
		last = last->next;
	}
}