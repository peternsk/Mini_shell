
#include "minishell.h"

long long	ft_atoi_long(const char *str)
{
	long long	i;
	long long	result;
	long long	pos_neg_sign;

	i = 0;
	result = 0;
	pos_neg_sign = 1;
	if (!str)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos_neg_sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * pos_neg_sign);
}

int	ft_is_strdigit(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if ((str[0] == '-' || str[0] == '+') && i == 0)
				i++;
			if (str[i] != '\0')
			{
				if (ft_isdigit(str[i]) != 1)
					return (-1);
			}
			i++;
		}
		return (0);
	}
	return (-1);
}

void	expan_exit(char **av)
{
	long long	_res;

	if (ft_is_strdigit(av[1]) == 0)
	{
		_res = ft_atoi_long(av[1]);
		if (_res >= INT_MAX || _res <= INT_MIN)
			write(2, "exit: numeric argument required\n",
				ft_strlen("exit: numeric argument required\n"));
		else
			exit((int)_res);
	}
	else
	{
		write(2, "exit: numeric argument required\n",
			ft_strlen("exit: numeric argument required\n"));
		exit(255);
	}
}


void	ft_exit(t_cmd *exi)
{
	if (exi)
	{
		if (exi->av_cmd)
		{
			if (size(exi->av_cmd) > 2)
			{
				if (ft_expand_exit(exi->av_cmd) == true)
					g_exit_status = 255;
				else 
					exit(1);
			}
			else
			{
				if (exi->av_cmd[1] == NULL)
					exit(0);
				else
					expan_exit(exi->av_cmd);
			}
		}
	}
}
