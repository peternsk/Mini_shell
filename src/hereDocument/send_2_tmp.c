#include "minishell.h"


// void    send_2_tmp(t_heredoc **lst, t_minish *m_s)
// {
//     t_heredoc *tmp;
//     int fd;

//     tmp = *lst;
//     fd = open("/tmp/heredoc", O_RDWR | O_CREAT | O_TRUNC,  07777);
//     while(tmp)
//     {
//         herelist_exp(lst, &m_s->envVarlst, m_s);
//         ft_putstr_fd(tmp->str, fd);
//         tmp = tmp->next;
//     }
//     close(fd);
//     fd = open("/tmp/heredoc", O_RDONLY,  07777);
//     dup2(fd, 0);
//     close(fd);
// }

void    send_2_tmp(t_heredoc **lst, t_minish *m_s, int index)
{
    t_heredoc *tmp;
    int fd;
    char *file_name;

    tmp = *lst;
	printf("creating file[%d]\n", index);
    file_name = ft_strjoin("/tmp/heredoc", ft_itoa(index));
    add_garbage(file_name);
    fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC,  07777);
    while(tmp)
    {
        herelist_exp(lst, &m_s->envVarlst, m_s);
        ft_putstr_fd(tmp->str, fd);
        tmp = tmp->next;
    }
    close(fd);
    free(file_name);
	printf("end file[%d]\n", index);
    // fd = open(file_name, O_RDONLY,  07777);
    // dup2(fd, 0);
    // close(fd);
}

void    free_here_list(t_heredoc **list)
{
    t_heredoc *tmp;
    
    if (list)
    {
        while (*list != NULL)
        {
            tmp = (*list)->next;
            free(*list);
            (*list) = tmp;
        }
        *list = NULL;
    }
}