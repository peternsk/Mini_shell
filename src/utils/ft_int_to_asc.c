
#include "minishell.h"

static int	ft_nblen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_int_to_ascii(int n)
{
	int		len;
	char	*str;

	len = ft_nblen(n);
	str = (char *)malloc_and_add((len + 1) * sizeof(char));
	if (!str)
		return (str);
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		if (str[0] == '-' && n < 0)
			str[len--] = '0' - (n % 10);
		else
			str[len--] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
