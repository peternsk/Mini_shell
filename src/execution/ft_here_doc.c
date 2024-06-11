
#include "minishell.h"

int	ft_here_doc(t_files *files, t_cmd *current)
{
	char	*input;

	input = NULL;
	(void)current;
	if (files)
	{
		if (files->type == here_doc && files->made == 0)
		{
			while (1)
			{
				input = readline("> ");

				if (!input)
					break ;
				if (ft_strncmp(input, files->name, ft_strlen(input)) == 0)
					break ;
			}
			files->made = -1;
		}
	}
	return (0);
}
