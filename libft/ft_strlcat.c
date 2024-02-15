/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:40:10 by pnsaka            #+#    #+#             */
/*   Updated: 2023/01/12 18:13:08 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	size_t	dststck;

	i = 0;
	if (!dst)
		return (ft_strlen(src));
	if (!src)
		return (0);
	dststck = ft_strlen(dst);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize < dst_len || dstsize == 0)
	{
		return (src_len + dstsize);
	}
	if (dstsize - 1 > dst_len)
	{
		while (dstsize - 1 > dst_len && src[i])
			dst[dst_len++] = src[i++];
		dst[dst_len] = '\0';
	}
	return (dststck + src_len);
}
