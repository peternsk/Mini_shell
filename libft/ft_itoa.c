/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:52:09 by pnsaka            #+#    #+#             */
/*   Updated: 2023/02/01 11:47:22 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(int n)
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

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_nlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
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
