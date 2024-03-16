/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:50:52 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/16 13:26:06 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*--- MACROS ---*/
# define INPUT "░▒▓███\001\e[0m\e[33m\002 Minishell>> \001\e[0m\002"


/*--- ENUM && STRUCT ---*/
typedef enum token_type 
{
	command,
	argument,
	sgl_quote_arg,
	dbl_quote_arg,
	out_p_redir,
	in_p_redir,
	apnd_op_redir,
	here_doc,
	pipe_,
	dbl_pipe_
}			token_type;

/*--- ENUM FLAG ---*/
typedef enum flag_swtch 
{
	FLAG_OFF,
	FLAG_ON
}	flag_swtch;

typedef	struct s_token
{
	struct s_token *prev;
	struct s_token *next;
	int	token_id;
	char *value;
	char *expValue;
	int type;
	int endToken;
} t_token;

typedef	struct s_cmdlts
{
	struct s_cmdlts *prev;
	struct s_cmdlts *next;
	int index;
	struct s_redlst *redlst;
	char **command;
} t_cmdlts;

typedef	struct s_redlts
{
	struct s_cmdlst *prev;
	struct s_cmdlst *next;
	int redtype;
	char *filename;
} t_redlts;

typedef	struct s_flags
{
	int		sgl_flag;
	int		dbl_flag;
	int		wsp_flag;
	int		met_flag;
	int		otc_flag;
	int		found_flag;
	int		flag_sw;
} t_flags;

/*--- ENV STRUCT ---*/
typedef struct	s_env
{
	struct	s_env *prev;
	struct	s_env *next;
	char 	*key;
	char 	*value;
} t_env;


typedef struct	s_minish
{
	t_token  *token_lst;
	t_env	 *envVarlst;
	t_flags  *flags;
	char	 *input;
	int		 index;
	int 	 pipe_num;
    int 	 in_redr_num;
    int 	 out_redr_num;
	int		 read_flag;
	int 	 s;
	int 	 e;
} t_minish;

#endif