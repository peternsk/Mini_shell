

#include "minishell.h"

int	put_int_fd(t_files *file)
{
	int	fd_name;

	if (file->name && file->made == 0)
	{
		file->made = 1;
		fd_name = open(file->name, O_WRONLY | O_CREAT, 07777);
		if (fd_name < 0)
			return (perror(file->name), file->error = 1, -1);
		close(fd_name);
	}
	return (-1);
}

int	change_stdout(t_files *files)
{
	t_files	*current;

	if (files)
	{
		current = files;
		while (current != NULL)
		{
			if (current->type == OPR)
				put_int_fd(current);
			current = current->next;
		}
	}
	return (-1);
}
