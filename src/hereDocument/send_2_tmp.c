#include "minishell.h"

void    send_2_tmp(t_heredoc **lst)
{
    printf("IN HERE !!!!!!!!!!!!\n");
    t_heredoc *tmp;
    int fd;

    tmp = *lst;
    fd = open("/tmp/heredoc", O_RDWR | O_CREAT | O_TRUNC , 0644);
    if(fd >= 0)
        printf("fd exist\n");
    else
        printf("fd dont exist %d\n", fd);
    while(tmp)
    {
        ft_putstr_fd(tmp->expstr, fd);
        tmp = tmp->next;
    }
    dup2(fd, 0);
    // close(fd);
}