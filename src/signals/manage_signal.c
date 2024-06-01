#include "minishell.h"

void ctrl_c_parent()
{
	printf(" we are in the parent\n");
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void exit_here_doc()
{
	printf(" we are in the function here doc\n");
	exit(EXIT_FAILURE);
}
void ctrl_quit_childs()
{
	printf(" we are in the childs  quit \n");
	return ;
}
void	ctrl_c_childs()
{
	printf(" we are in the childs ctr-c\n");
	return ;
}
void manage_signal (int id)
{
	if (id == 0)
	{
		printf("we are in the childs\n");
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
	else
	{
		printf("we are in the parent \n");
		signal(SIGINT, ctrl_c_parent);
		signal(SIGQUIT, SIG_IGN); 
	}
}
