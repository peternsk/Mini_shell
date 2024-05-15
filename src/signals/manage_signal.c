#include "minishell.h"

void ctrl_c_parent()
{
	// function mal need to be fix
	// printf("parent\n");
    // readline(INPUT); // printf("\n");
	// rl_line_buffer = INPUT;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	// printf("\n");
	// printf(INPUT);
}
void ctrl_quit_childs()
{
	return ;
}
void	ctrl_c_childs()
{
	printf("ctr \\");
	return ;
}
// void nothing(){ printf("say my name ... \n");}

void manage_signal (int id)
{
	if (id == 0)
	{
		signal(SIGINT, ctrl_c_childs);
		signal(SIGQUIT, ctrl_quit_childs); 
	}
	else
	{
		signal(SIGINT, ctrl_c_parent);
		signal(SIGQUIT, SIG_IGN); 
	}
}
