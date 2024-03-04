/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:56:06 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/04 11:04:37 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <term.h>
#include <stdbool.h>
#include "define.h"
#include "error.h"
#include "garbage.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "../libft/libft.h"

/*--- create struct ---*/
t_flags		 *init_flag(void);
t_minish 	*init_ms(void);

/*--- node && token ---*/
t_token 	*set_token(t_token *token, t_minish *m_s);;
void	    add_token_to_end(t_token **lst, t_token *token);
int		    count_token(t_token *token);
void	    print_token(t_token *lst);
void	    assign_type(t_token *token, t_minish *m_s);
void	    meta_type(t_token *token);
void	    assign_token_type(t_token **lst, t_minish *m_s);


/*--- quote && double quote ---*/
void     	find_next_quote(t_minish *m_s, char quote_type);

/*--- command ---*/
void	    create_cmd(t_minish *m_s);
void	    find_cmd(t_minish *m_s);
bool		is_space(char c);

/*--- meta char ---*/
bool		is_meta(char c);
void	    find_meta(t_minish *m_s, char meta);


/*--- tokenisation ---*/
void        flag_switch(char c, t_minish *m_s);
void		split_token(t_minish *m_s);
void        tokenizer(t_minish *m_s);
t_token     *create_token(t_minish *m_s);

/*---  utils ---*/
char 		*ft_strncpy(char *s1, char *s2, int n);
size_t		ft_strlen_(const char *s);
char	    *ft_trim(char const *s1, char const *set);

/*--- ascii font ---*/
void        ft_ascii_font(void);



#endif
 