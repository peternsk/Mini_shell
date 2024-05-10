
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
#include <limits.h>
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
void		print_env_lst(t_env *lst);

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

char        **list_to_tab(t_env **lst);
char        *token_2_str(t_env *env_node);
int		    count_env_node(t_env *node);

/*====================================================*/
/*=                     BUILDER                      =*/
/*====================================================*/

void        ft_removeQuotes(t_token **tkLst);
int			ft_nbrOfNode(t_token **lst);
t_cmdlts 	*set_cmdNode(t_cmdlts *cmd, t_minish *m_s);
void		add_cmdNode_to_end(t_cmdlts **lst, t_cmdlts *cmd);
void	    print_cmdLst(t_cmdlts **lst);                                                                                                                                                                    
void	    printArray(char **arr);
void 	    ft_createCmdLst(t_minish *m_s);
void        combineTokValue(t_token **lst);
void        merge_token(t_token **lst);
void        delete_token(t_token **lst, int tokToDel_id);
void	    ft_cmdBuilder(t_minish *m_s, t_token **toklst, t_cmdlts **cmdlst);

/*---- REDIRECTION ----*/
t_redlts 	*setRed(char *redtype, char *filename);
void	    add_redNode_to_end(t_redlts **redNode, t_redlts *newNode);
int		    countNbRednode(t_token **lst);
void		print_redLst(t_redlts **lst);

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
void        free_list(t_token **list);

/*====================================================*/
/*=                  HERE DOCUMENT                   =*/
/*====================================================*/

/* init linked list*/
t_heredoc   *intHereLst(t_heredoc *node, char *input);
void	    add_here_to_end(t_heredoc **lst, t_heredoc *var);
t_heredoc   *create_here_lst(t_minish *m_s, char *input);

/* parsing */
bool        end_key(char c);
char        *find_here_key(t_heredoc *node, t_minish *m_s);
void        hereExp(t_heredoc *node, t_env **lst, t_minish *m_s);
void	    herelist_exp(t_heredoc **lst, t_env **envVarlst, t_minish *m_s);

/* core function */
bool        delim_cmp(char *input, char *delimiter);
void	    check_here_doc(t_minish *m_s, t_redlts **lst);
void        reset_ms(t_heredoc *node, t_minish *m_s);
void        replace_here_str(t_heredoc *node);
void        ft_here_exitStatus(t_heredoc *token, t_minish *m_s);

/* print test */
void	    print_here_lst(t_heredoc *lst);

/*====================================================*/
/*=                 init_cmd execution               =*/
/*====================================================*/

void        init_cmds(char **envp, t_minish *m_s);
void        add_cmds_files(t_cmd **node, t_cmd *new, t_redlts *files);
void        cout_cmds_pipes(t_cmd *cmds);
void        add_files(t_cmd *cmd, t_redlts *new_files);
int         type_cmds(char *s);
int         run_commands(t_cmd *cmds);
char        *get_envp_path(char **envp);
int         single_command(t_cmd *cmd, char **envp, char *envp_path);
int         commands(t_cmd *cmds, char *envp_path);
void        wait_childs(t_cmd *cmds);
int         execute_command(t_cmd *current, char **envp, char *envp_path);
char        *get_cmd_path(char *path, char *cmd);
void        which_files(t_cmd *current);
void        is_change_std(t_cmd *current);
int         ft_append(t_files *file);
int         change_stdint(t_files *file);
int         change_stdout(t_files *files);
int         handel_builtin(t_cmd *cmd);
void        ft_pwd();
void        ft_cd(t_cmd *cmds);
void        ft_echo(t_cmd *ec);
void        ft_export(t_cmd *built, char **envp, char **vars, bool print);
char        **addEnvp(char **envp, char **vars);
void        printEnvp(char **envp);
char        **check_duplicate(char **vars);
bool        is_same(char *s, char *v);
char        **new_envp(char **envp, char **new, char *vars, int index);
int         same_var_value(char **envp, char *var);
int         same_varibale(char **envp, char *var);
int         is_add(char **envp, char *var, int kv);
int         size(char **env);
void        ft_unset(t_cmd *unset);
char        *is_same_key_value(char **envp, char *s, int index);
void        ft_env(t_cmd *env);
void        ft_exit(t_cmd *exi);
t_manage_fds *init_manage_fd(int copy_fd, int error, int is_open);
int         is_files_valide(t_cmd *cmds);
int         ft_here_doc(t_files *files, t_cmd *current);


/*====================================================*/
/*=                    signal                        =*/
/*====================================================*/

void manage_signal(int id);


#endif
 