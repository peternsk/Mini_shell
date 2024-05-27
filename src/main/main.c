

#include "../include/minishell.h"

int exit_status = 0;

/*reste a teste le main avec tout*/

int		main(int ac, char **av, char **env)
{
	(void)av;
	t_minish	*m_s;

	m_s = NULL;
	ft_ascii_font();
	if(ac > 0)
	{
		manage_signal(-1);
		while(1)
		{
			m_s = init_ms();
			m_s->flags = init_flag();
			m_s->input = readline(INPUT);
			if (!m_s->input)
				return (printf("exit\n"), 0);
			add_history(m_s->input);
			set_and_update_env(m_s, env);
			if(ft_lexer(&m_s->token_lst) == true)
				build_and_exec(m_s);
		}
	}
	else
		printf("arg missing !!\n");
}
