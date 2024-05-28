#include "minishell.h"

void ctrl_c_parent()
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void exit_here_doc()
{
	exit(1);
}
void ctrl_quit_childs()
{
	exit(0);
}
void	ctrl_c_childs()
{
	exit(0);
}
void manage_signal (int id)
{
	if (id == 0)
	{
		signal(SIGINT, ctrl_c_childs);
		signal(SIGQUIT, ctrl_quit_childs); 
	}
	else if (id == 3)
	{
		signal(SIGINT, exit_here_doc);
		signal(SIGQUIT, SIG_IGN); 
	}
	else
	{
		signal(SIGINT, ctrl_c_parent);
		signal(SIGQUIT, SIG_IGN); 
	}
}
