#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "define.h"
# include "error.h"
# include "garbage.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "readline/history.h"
# include "readline/readline.h"
# include <signal.h>
# include <term.h>
# include <unistd.h>
/*====================================================*/
/*=                  GLOBAL VARIABLE                 =*/
/*====================================================*/

extern int		g_exit_status;

/*====================================================*/
/*=                      PARSER                      =*/
/*====================================================*/

void			begin_lexing(void);
void			begin_set_env_var(void);

/*--- create struct ---*/
t_flags			*init_flag(void);
t_minish		*init_ms(void);

/*--- node && token ---*/
t_token			*set_token(t_token *token, t_minish *m_s);
void			add_token_to_end(t_token **lst, t_token *token);
int				count_token(t_token *token);
void			assign_type(t_token *token, t_minish *m_s);
void			meta_type(t_token *token);
void			assign_token_type(t_token **lst, t_minish *m_s);
void			print_real_list(t_token *lst);
char			*rightType(int type);

/*--- quote && double quote ---*/
void			find_next_quote(t_minish *m_s, char quote_type);
bool			is_quotes(char c);

/*--- command ---*/
void			create_cmd(t_minish *m_s);
void			find_cmd(t_minish *m_s);
bool			is_space(char c);

/*--- meta char ---*/
bool			is_meta(char c);
void			find_meta(t_minish *m_s, char meta);

/*--- tokenisation ---*/
void			flag_switch(char c, t_minish *m_s);
void			split_token(t_minish *m_s);
void			tokenizer(t_minish *m_s);
t_token			*create_token(t_minish *m_s);

/*--- ascii font ---*/
void			ft_ascii_font(void);

/*====================================================*/
/*=                      LEXER                       =*/
/*====================================================*/

/*---  meta_char ---*/
bool			ft_lexer(t_token **lst);
bool			prs_ast_pipe(t_token **lst);
bool			prs_ast_dlb_meta(t_token **lst);
bool			prs_ast_redir(t_token **lst);
void			begin_parsing(void);
void			set_delimiter(t_token **lst);
void			set_file_red(t_token **lst);

/*====================================================*/
/*=                       ENV                        =*/
/*====================================================*/
void			print_env_lst(t_env *lst);

t_env			*int_env_var(t_env *node, char *env_row);
void			add_var_to_end(t_env **lst, t_env *var);
t_env			*create_var(t_minish *m_s, char *env_row);
void			set_env_lst(t_minish *m_s, char **env);

bool			char_search(char *tok_value, char c);
char			*find_tmp_key(t_token *tk, t_minish *m_s);
bool			find_key_in_list(t_env **lst, char *tmp_key);
void			ft_expend(t_token *token, t_env **lst, t_minish *m_s);
void			print_expend_tab(t_token **lst, t_env **env_varlst,
					t_minish *m_s);
char			**exp_split(char const *s, char c);

char			*find_var_env(t_env **lst, char **tmpvalue, char *tmp_key);
void			replace_token(t_token *token);

char			**list_to_tab(t_env **lst);
char			*token_2_str(t_env *env_node);
int				count_env_node(t_env *node);

/*====================================================*/
/*=                     BUILDER                      =*/
/*====================================================*/

void			ft_remove_quotes(t_token **tkLst);
int				ft_nbr_of_node(t_token **lst);
t_cmdlts		*set_cmd_node(t_cmdlts *cmd, t_minish *m_s);
void			add_cmd_node_to_end(t_cmdlts **lst, t_cmdlts *cmd);
void			print_comd_lst(t_cmdlts **lst);
void			print_array(char **arr);
void			ft_createcomd_lst(t_minish *m_s);
void			combine_tok_value(t_token **lst);
void			merge_token(t_token **lst);
void			delete_token(t_token **lst, int tokToDel_id);
void			ft_cmd_builder(t_minish *m_s, t_token **toklst,
					t_cmdlts **comd_lst);

/*---- REDIRECTION ----*/
t_files			*set_red(char *redtype, char *filename, t_minish *m_s);
void			rd_end(t_files **lst, t_files *red_node);
int				count_nbred_node(t_token **lst);
void			print_red_lst(t_files **lst);

/*====================================================*/
/*=                      UTILS                       =*/
/*====================================================*/

char			*ft_strncpy(char *s1, char *s2, int n);
size_t			ft_strlen(const char *s);
char			*ft_trim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
bool			ft_strcmp(char *tmp_key, char *envKey);
char			*ft_combine(char *s1, char *s2);
void			ft_end_token(t_token *token, t_minish *m_s);
void			free_list(t_token **list);
void			free_tabl(char **map);
bool			ft_search_char(char *str, char c);
char			*ft_int_to_ascii(int n);

/*====================================================*/
/*=                  HERE DOCUMENT                   =*/
/*====================================================*/

/* init linked list*/
t_heredoc		*int_here_lst(t_heredoc *node, t_minish *m_s, char *input);
void			add_here_to_end(t_heredoc **lst, t_heredoc *var);
t_heredoc		*create_here_lst(t_minish *m_s, char *input);

/* parsing */
bool			end_key(char c);
char			*find_here_key(t_heredoc *node, t_minish *m_s);
void			here_exp(t_heredoc *node, t_env **lst, t_minish *m_s);
void			herelist_exp(t_heredoc **lst, t_env **env_varlst,
					t_minish *m_s);

/* core function */
bool			delim_cmp(char *input, char *delimiter);
void			check_here_doc(t_minish *m_s, t_files **files);
void			reset_ms(t_heredoc *node, t_minish *m_s);
void			replace_here_str(t_heredoc *node);
void			ft_here_exit_status(t_heredoc *token, t_minish *m_s);
int				count_here_doc(t_files **lst);
void			empty_hereDoc(t_files *tmp);
void			last_here_doc(t_minish *m_s, t_files *tmp);
void			run_here_redlst(t_minish *m_s, t_files **lst);
void			send_2_tmp(t_heredoc **lst, t_minish *ms, t_files *tmp_files,
					int index);
int				the_last_heredoc(t_cmd *cmd);

/* UNLINK FILE */
t_unlnk			*int_unlnk_node(t_unlnk *node, char *filepath);
void			add_file_to_end(t_unlnk **lst, t_unlnk *var);
t_unlnk			*create_unlnk_node(t_minish *m_s, char *filepath);
void			unlnk_all_file(t_unlnk **lst);
void			print_unlnk_Lst(t_unlnk **lst);
void			create_filename_linklist(t_minish *m_s, t_files **lst);
void			add_filename_unlnk_lst(t_cmdlts **cmd, t_minish *m_s);

/* print test */
void			print_here_lst(t_heredoc *lst);

/*====================================================*/
/*=                 init_cmd execution               =*/
/*====================================================*/

char			**init_cmds(char **envp, t_minish *m_s);
void			add_cmds(t_cmd **node, t_cmd *new);
void			cout_cmds_pipes(t_cmd *cmds);
int				run_commands(t_cmd *cmds);
char			*get_envp_path(char **envp);
int				single_command(t_cmd *cmd, char **envp, char *envp_path);
int				commands(t_cmd *cmds, char *envp_path);
void			wait_childs(t_cmd *cmds);
int				execute_command(t_cmd *current, char *envp_path, int **array);
char			*get_cmd_path(char *path, char *cmd);
// void        is_change_std(t_cmd *current);
int				handel_builtin(t_cmd *cmd);
char			**check_duplicate(char **vars);

/*====================================================*/
/*=                    signal                        =*/
/*====================================================*/

void			manage_signal(int id);

/*====================================================*/
/*=                    bultin                        =*/
/*====================================================*/
char			*copy_value(char *str);
void			ft_pwd(void);
void			ft_cd(t_cmd *cmds);
t_env			*add_envp(char *vars);
void			ft_export(t_cmd *built, bool print);
void			ft_echo(t_cmd *ec);
int				is_same_key_value(t_env *new, char *vars, int index);
void			is_add_envp(t_env *env, char **arg);
int				size(char **env);
void			ft_env(t_cmd *env);
void			ft_exit(t_cmd *exi);
void			ft_unset(t_cmd *unset);
void			print_envp(char **envp);
int				is_same_key(t_env *env, char *var);
int				type_cmds(char *s);
bool			is_key(char *str);

/*====================================================*/
/*=                    files                        =*/
/*====================================================*/

int				is_files_valide(t_cmd *cmds);
int				ft_here_doc(t_files *files, t_cmd *current);
t_manage_fds	*init_manage_fd(int copy_fd, int error, int is_open);
int				change_stdint(t_files *file);
int				change_stdout(t_files *files);
void			add_files(t_cmd *cmd, t_redlts *new_files);
void			which_files(t_cmd *current);
int				ft_append(t_files *file);
t_files			*is_there_here_doc(t_cmd *current);
void			pipe_connect_and_files(t_cmd *current, int **array_pipe);
void			std_one_commande(t_cmd *current);

/*====================================================*/
/*=                   EXIT STATUS                    =*/
/*====================================================*/

t_exit_code		*init_exit_lst(t_exit_code *node, pid_t extCode);
void			add_exit_to_end(t_exit_code **lst, t_exit_code *var);
t_exit_code		*create_exit_code_lst(t_minish *m_s, pid_t extCode);
int				get_code(int exit_code);

void			print_ext_lst_lst(t_exit_code *lst);

/*====================================================*/
/*=                      MAIN                        =*/
/*====================================================*/

int				build_and_exec(t_minish *m_s);
void			set_and_update_env(t_minish *m_s, char **env, char **tmp);
t_minish		*init_structs(t_minish *m_s);

#endif
