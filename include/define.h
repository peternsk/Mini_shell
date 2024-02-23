/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergnas <lvergnas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:50:52 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/22 15:28:03 by lvergnas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

typedef enum token_type
{
	command,
	sgl_quote,
	dbl_quote,
	out_p_redir,
	in_p_redir,
	apnd_op_redir,
	here_doc,
	pipe_
}	token_type;

typedef enum arg_flag
{
	ON,
	OFF
}	arg_flag;

typedef struct s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	int				token_id;
	int				type;
	int				arg_flag;
	char			*command;
	char			**arg;
}	t_token;

typedef struct s_history
{
	struct s_history	*prev;
	struct s_history	*next;
	int					cmd_id;
	char				*hist_cmd;
}	t_history;

typedef struct s_minish
{
	t_token		*cmd;
	t_history	*cmd_history;
}	t_minish;

#endif