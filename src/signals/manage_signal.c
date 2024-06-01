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
	// printf(" we exit from the here doc \n");
	write(1, "\n", 1);
	rl_replace_line("", 0);
	exit(EXIT_FAILURE);
}
void ctrl_quit_childs()
{
	return ;
}
void	ctrl_c_childs()
{
	return ;
}
void manage_signal (int id)
{
	if (id == 0)
	{
		// printf("manage_siganal we are in the childs \n");
		signal(SIGINT, ctrl_quit_childs);
		signal(SIGQUIT, ctrl_quit_childs); 
		return ;
	}
	else if (id == 3)
	{
		printf("manage_siganal we are in the here doc \n");
		signal(SIGINT, exit_here_doc);
		signal(SIGQUIT, SIG_IGN); 
	}
	if (id == -1)
	{
		printf("we manage_signal for the parent\n");
		signal(SIGINT, ctrl_c_parent);
		signal(SIGQUIT, SIG_IGN); 
	}
}
