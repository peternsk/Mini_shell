#include "minishell.h"

void ctrl_c_parent()
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
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
		printf("we are in childs\n");
		signal(SIGINT, ctrl_c_childs);
		signal(SIGQUIT, ctrl_quit_childs); 
	}
	else
	{
		signal(SIGINT, ctrl_c_parent);
		signal(SIGQUIT, SIG_IGN); 
	}
}
