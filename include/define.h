#ifndef DEFINE_H
# define DEFINE_H

/*--- MACROS ---*/
# define INPUT "░▒▓███\001\e[0m\e[33m\002 Minishell>> \001\e[0m\002"
# define HERE_INPUT "> "

/*--- PRINTF COLOR ---*/
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define RESET "\x1B[0m"

# include "garbage.h"
# include <stdbool.h>

typedef struct s_redlts	t_redlts;

/*--- ENUM && STRUCT ---*/
typedef enum token_type
{
	command,
	argument,
	SQA,
	DQA,
	OPR,
	IPR,
	APOR,
	here_doc,
	pipe_,
	DBLP,
	DBLE,
	delimter,
	_file
}						token_type;

/*--- ENUM FLAG ---*/
typedef enum flag_swtch
{
	FLAG_OFF,
	FLAG_ON
}						flag_swtch;

typedef struct s_files
{
	int					type;
	int					index;
	char				*name;
	char				*agrv;
	int					made;
	int					here_count;
	int					index_out;
	int					put_last;
	int					error;
	int					heredoc_id;
	char				*name_here_doc;
	int					fd_here;
	struct s_files		*next;
	struct s_files		*prev;
	// struct s_manage_fds *manage_fd;
	int					manage_fd;
}						t_files;

typedef struct s_unlnk
{
	struct s_unlnk		*prev;
	char				*filepath_name;
	struct s_unlnk		*next;
}						t_unlnk;
typedef struct s_token
{
	struct s_token		*prev;
	struct s_token		*next;
	int					token_id;
	char				*value;
	char				*exp_value;
	int					type;
	int					end_token;
	int					to_merge;
	int					set_to_cmd;
}						t_token;

typedef struct s_cmdlts
{
	struct s_cmdlts		*prev;
	struct s_cmdlts		*next;
	int					index;
	int					arr_len;
	char				**command;
	t_files				*redlst;
}						t_cmdlts;

typedef struct s_flags
{
	int					sgl_flag;
	int					dbl_flag;
	int					wsp_flag;
	int					met_flag;
	int					otc_flag;
	int					found_flag;
	int					flag_sw;
}						t_flags;

/*--- ENV STRUCT ---*/
typedef struct s_env
{
	struct s_env		*prev;
	struct s_env		*next;
	char				*key;
	char				*value;
	bool				eql_sign;
}						t_env;

/*--- HERE STRUCT ---*/
typedef struct s_heredoc
{
	struct s_heredoc	*prev;
	char				*str;
	char				*expstr;
	bool				made;
	int					index;
	struct s_heredoc	*next;
}						t_heredoc;

typedef struct s_exit_code
{
	pid_t				pid;
	struct s_exit_code	*next;
	struct s_exit_code	*prev;
}						t_exit_code;

typedef struct s_minish
{
	t_token				*token_lst;
	t_env				*env_varlst;
	t_cmdlts			*comd_lst;
	t_flags				*flags;
	t_heredoc			*herelst;
	t_exit_code			*extlst;
	t_unlnk				*unlnk_lst;
	t_garbage			*garbage;
	int					here_id;
	char				*input;
	char				**tab_env;
	int					index;
	int					pipe_num;
	int					in_redr_num;
	int					out_redr_num;
	int					read_flag;
	int					cmd_all_set;
	int					cmd_counter;
	int					s;
	int					e;
	char				**update_envp;
	char				**tmp;
}						t_minish;

/*----------------- CMDS EXECUTION -------------*/

/*--- FILES/ ---*/

typedef struct s_redlts
{
	struct s_redlts		*prev;
	struct s_redlts		*next;
	char				*redtype;
	char				*filename;
	int					heredoc_id;
}						t_redlts;

/*--- PIPE/ ---*/
typedef struct s_cmd
{
	int					type;
	pid_t				id;
	int					**pipes;
	char				**av_cmd;
	char				*cmd_name;
	char				**envp;
	int					index;
	bool				is_vars;
	int					nb_cmds;
	int					nb_pipes;
	int					exit_here_doc;
	int					is_file_on;
	struct s_cmd		*next;
	t_minish			*glob;
	t_files				*files;
}						t_cmd;

typedef struct s_manage_fds
{
	int					type;
	int					error;
	int					_is_use;
	int					is_open;
	int					copy_fd;
	struct s_manage_fds	*next;
}						t_manage_fds;

#endif