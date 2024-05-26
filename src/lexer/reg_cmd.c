#include "minishell.h"

bool	is_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return(true);
	return(false);
}

void	create_cmd(t_minish *m_s)
{
	m_s->e = m_s->s;
	create_token(m_s);
	m_s->s = m_s->e + 1;
}
static void     set_char_before_meta(t_minish *m_s)
{
    if (m_s->e > m_s->s)
    {
        m_s->e--;
        create_token(m_s);
        m_s->s = ++m_s->e;
        m_s->flags->otc_flag = FLAG_OFF;
    }
}

static void     set_meta(t_minish *m_s)
{
    if (is_meta(m_s->input[m_s->e]))
	{
        m_s->flags->met_flag = FLAG_ON;
        find_meta(m_s, m_s->input[m_s->s]);
    }
}

static void     set_quotes(t_minish *m_s)
{
    if(is_quotes(m_s->input[m_s->e]))
	{
        if(m_s->input[m_s->e] == 34)
        {
            m_s->flags->dbl_flag = FLAG_ON;
            m_s->flags->found_flag = FLAG_OFF;
            find_next_quote(m_s, 34);
            m_s->flags->dbl_flag = FLAG_OFF;
        }
        if(m_s->input[m_s->e] == 39)
        {
            m_s->flags->sgl_flag = FLAG_ON;
            m_s->flags->found_flag = FLAG_OFF;
            find_next_quote(m_s, 39);
            m_s->flags->sgl_flag = FLAG_OFF;
        }
    }
}

void find_cmd(t_minish *m_s)
{
    m_s->e = m_s->s;
    while (m_s->input[m_s->e] && !is_space(m_s->input[m_s->e]))
	{
        m_s->flags->otc_flag = FLAG_ON;
        if (is_meta(m_s->input[m_s->e]) || is_quotes(m_s->input[m_s->e])) 
		{
            set_char_before_meta(m_s);
            if(is_meta(m_s->input[m_s->e]))
                set_meta(m_s);
            if(is_quotes(m_s->input[m_s->e]))
                set_quotes(m_s);
        }
        m_s->e++;
    }
    if (m_s->e > m_s->s)
    {
        m_s->e--;
        create_token(m_s);
    }
    m_s->s = m_s->e + 1;
}
