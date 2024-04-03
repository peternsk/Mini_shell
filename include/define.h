/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:50:52 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/03 10:12:45 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*--- MACROS ---*/
# define INPUT "░▒▓███\001\e[0m\e[33m\002 Minishell>> \001\e[0m\002"

/*--- PRINTF COLOR ---*/
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


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
	dbl_pipe_,
	delimter,
	_file
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
	int	to_merge;
	int setToCmd;
} t_token;

typedef	struct s_cmdlts
{
	struct s_cmdlts *prev;
	struct s_cmdlts *next;
	int index;
	int arrLen;
	char **command;
	struct s_redlst *redlst;
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
	t_cmdlts *cmdLst;
	t_flags  *flags;
	char	 *input;
	int		 index;
	int 	 pipe_num;
    int 	 in_redr_num;
    int 	 out_redr_num;
	int		 read_flag;
	int		 cmdAllSet;
	int		 cmdCounter;
	int 	 s;
	int 	 e;
} t_minish;

#endif