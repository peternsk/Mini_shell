/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/10 14:31:37 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exit_status = 0;

int		main(int ac, char **av, char **env)
{
	
	
	t_minish *m_s;
	(void)av;

	ft_ascii_font();
	if(ac > 0)
	{
		while(1)
		{
			m_s = init_ms();
			m_s->flags = init_flag();
			m_s->input = readline(INPUT);
			add_history(m_s->input);
			begin_setEnvVar();
			set_env_lst(m_s, env);
			begin_lexing();
			tokenizer(m_s);	
			begin_parsing();
			ft_lexer(&m_s->token_lst);
			print_expendTab(&m_s->token_lst, &m_s->envVarlst, m_s);
			ft_removeQuotes(&m_s->token_lst);
			setDelimiter(&m_s->token_lst);
			setFile(&m_s->token_lst);
			printRealList(m_s->token_lst);
			ft_createCmdLst(m_s);
			merge_token(&m_s->token_lst);
			combineTokValue(&m_s->token_lst);
			printRealList(m_s->token_lst);
			ft_cmdBuilder(&m_s->token_lst, &m_s->cmdLst);
			print_cmdLst(&m_s->cmdLst);
		}
	}
	else
		printf("arg missing !!\n");
}
// echo $USER$?$USER
// echo "'"$USER"'"
// echo bonjour comment ca va
// echo | ls | grep everything | $USER | path
// "e"'c'ho 'b'"o"nj"o"'u'r
// echo "e"'ch'o 'b'"o"n'jo'u"r"! ls -la "sal"ut < file1 > file2 | ls > file3 << EOF
// echo bonjour ls -la salut
// ec"ho" bon"jour" ls -la salut
// e"ch"o bo"njo"ur | comm"ent"XX "he"ll'o' | ma"k"e ma"in".c | ls -la pourquoi ?
// ech"o"  "$USER" | "comm"entXX "$PATH"  |  ma"in.c" "$HOME" | ls -la pourquoi ?
// echo
// ec"ho" sa"lu"t "b"o"n"j"our"
// e"ch"o bo"njo"ur >> file_1.txt | comm"ent"XX "he"ll'o' > file_2 | ma"k"e ma"in".c << EOF
// e"ch"o bo"njo"ur >> file_1.txt  >> file_2.txt >> file_3.txt >> file_4.txt $USER$USERR$USER
 
// echo>>file_1|comment hello>file_2|make<<EOF>file_3
// echo >> file_1 | comment hello > file_2 | make << EOF > file_3
// e"c"ho >> f'i'le"_1" $USER | c"o"mm'en't 'h'e"ll"o > fi"le_2" $ZDOTDIR | ma"ke" << EO"F"
// e"ch"o bo"njo"ur >> file_1.txt  >> file_2.txt >> file_3.txt >> file_4.txt $USER$USERR$USER | ls -la < file_5 << EOF > file_6