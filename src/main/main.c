

#include "../include/minishell.h"

int exit_status = 0;

void m_ctrl_c_parent()
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int		main(int ac, char **av, char **env)
{
	(void)av;
	t_minish	*m_s;

	m_s = NULL;
	if(ac > 0)
	{
		ft_ascii_font();
		manage_signal(-1);
		while(1)
		{
			m_s = init_ms();
			m_s->flags = init_flag();
			m_s->input = readline(INPUT);
			if (!m_s->input)
				return (all_free(), printf("exit\n"), 0);
			add_history(m_s->input);
			set_and_update_env(m_s, env);
			if(ft_lexer(&m_s->token_lst) == true)
				build_and_exec(m_s);
			add_filename_unlnk_lst(&m_s->cmdLst, m_s);
			print_unlnk_Lst(&m_s->unlnk_lst);
			unlnk_all_file(&m_s->unlnk_lst);
		}
	}
	else
		printf("arg missing !!\n");
}
