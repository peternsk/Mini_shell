/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergnas <lvergnas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:56:06 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/28 11:55:33 by lvergnas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "define.h"
# include "error.h"
# include "../libft/libft.h"

/*   test   */
char	*clt_input(char *cmd);

/*   TEST LOU   */
typedef	struct s_cmdlts
{
	struct s_cmdlts *prev;
	struct s_cmdlts *next;
	int	index;
	// linked redirect
	char **cmd; // cmd -option args
}	t_cmdlts;

typedef struct s_info
{
	t_cmdlts *cmdlts;
	int		nb_cmds;
	char	*env_path;
	char	**them_paths;
	char	**cmd_args;
}   t_info;

#endif
