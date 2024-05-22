#include "minishell.h"

// les str danss le tmp->expstr son null
void    send_2_tmp(t_heredoc **lst)
{
    // printf("IN HERE !!!!!!!!!!!!\n");
    t_heredoc *tmp;
    int fd;

    tmp = *lst;
    fd = open("/tmp/heredoc.txt", O_RDWR | O_CREAT,  07777);
    // if(fd >= 0)
    //     printf("fd exist %d\n", fd);
    // else
    //     printf("fd dont exist %d\n", fd);
    while(tmp)
    {
        ft_putstr_fd(tmp->expstr, fd);
        // printf("------------------------------------------------------%s\n", tmp->expstr);
        tmp = tmp->next;
    }
    dup2(fd, 0);
    // close(fd);
}