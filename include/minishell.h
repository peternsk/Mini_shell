/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:56:06 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/03 09:50:07 by pnsaka           ###   ########.fr       */
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

/*====================================================*/
/*=                  GLOBAL VARIABLE                 =*/
/*====================================================*/

extern int exit_status;

/*====================================================*/
/*=                      PARSER                      =*/
/*====================================================*/

void	    begin_lexing(void);
void		begin_setEnvVar(void);

/*--- create struct ---*/
t_flags		*init_flag(void);
t_minish 	*init_ms(void);

/*--- node && token ---*/
t_token 	*set_token(t_token *token, t_minish *m_s);;
void	    add_token_to_end(t_token **lst, t_token *token);
int		    count_token(t_token *token);
void	    assign_type(t_token *token, t_minish *m_s);
void	    meta_type(t_token *token);
void	    assign_token_type(t_token **lst, t_minish *m_s);
void	    printRealList(t_token *lst);
char        *rightType(int type);


/*--- quote && double quote ---*/
void     	find_next_quote(t_minish *m_s, char quote_type);
bool	    is_quotes(char c);

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



/*--- ascii font ---*/
void        ft_ascii_font(void);

/*====================================================*/
/*=                      LEXER                       =*/
/*====================================================*/

/*---  meta_char ---*/
void        ft_lexer(t_token **lst);
bool	    prs_ast_pipe(t_token **lst);
bool	    prs_ast_dlb_meta(t_token **lst);
bool	    prs_ast_redir(t_token **lst);
void		begin_parsing(void);
void        setDelimiter(t_token **lst);
void        setFile(t_token **lst);

/*====================================================*/
/*=                       ENV                        =*/
/*====================================================*/

t_env 	    *intEnvVar(t_env *node, char *env_row);
void	    add_var_to_end(t_env **lst, t_env *var);
t_env       *create_var(t_minish *m_s, char *env_row);
void        set_env_lst(t_minish *m_s, char **env);

bool        char_search(char *tok_value, char c);
char        *find_tmp_key(t_token *tk, t_minish *m_s);
bool 		find_key_in_list(t_env **lst, char *tmpKey);
void        ft_expend(t_token *token, t_env **lst, t_minish *m_s);
void	    print_expendTab(t_token **lst, t_env **envVarlst, t_minish *m_s);
char		**exp_split(char const *s, char c);

char        *findVarEnv(t_env **lst, char **tmpvalue, char *tmpKey);
void        replaceToken(t_token *token);



/*====================================================*/
/*=                     BUILDER                      =*/
/*====================================================*/

void        ft_removeQuotes(t_token **tkLst);
int			ft_nbrOfNode(t_token **lst);
t_cmdlts 	*set_cmdNode(t_cmdlts *cmd, t_minish *m_s);
void		add_cmdNode_to_end(t_cmdlts **lst, t_cmdlts *cmd);
void		print_cmdLst(t_cmdlts *lst);                                                                                                                                                                     
void	    printArray(char **arr);
void 	    ft_createCmdLst(t_minish *m_s);



/*====================================================*/
/*=                      UTILS                       =*/
/*====================================================*/

char 		*ft_strncpy(char *s1, char *s2, int n);
size_t		ft_strlen(const char *s);
char	    *ft_trim(char const *s1, char const *set);
char	    **ft_split(char const *s, char c);
char	    *ft_strdup(const char *s1);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
bool        ft_strcmp(char *tmpKey, char *envKey);
char        *ft_combine(char *s1, char *s2);
void        ft_endToken(t_token *token, t_minish *m_s);
void        merge_token(t_token **lst);


#endif
 