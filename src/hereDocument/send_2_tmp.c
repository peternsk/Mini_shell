#include "minishell.h"

// les str danss le tmp->expstr son null
void    send_2_tmp(t_heredoc **lst, t_minish *m_s)
{
    // printf("IN HERE !!!!!!!!!!!!\n");
    t_heredoc *tmp;
    int fd;

    tmp = *lst;
    fd = open("/tmp/heredoc", O_RDWR | O_CREAT | O_TRUNC,  07777);
    if(fd >= 0)
        printf("fd exist %d\n", fd);
    else
        printf("fd dont exist %d\n", fd);
    while(tmp)
    {
        herelist_exp(lst, &m_s->envVarlst, m_s);
        ft_putstr_fd(tmp->str, fd);
        // printf("------------------------------------------------------%s\n", tmp->expstr);
        // printf("------------------------------------------------------%s\n", tmp->str);
        tmp = tmp->next;
    }
    close(fd);
    fd = open("/tmp/heredoc", O_RDONLY,  07777);
    dup2(fd, 0);
    
}