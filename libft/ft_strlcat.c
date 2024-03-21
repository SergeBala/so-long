/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:17 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/24 18:00:55 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len_dest = 0;
	len_src = ft_strlen(src);
	if (dst == 0 && size == 0)
		return (len_src);
	len_dest = ft_strlen(dst);
	i = len_dest;
	if (size <= len_dest || size == 0)
		return (len_src + size);
	while (src[j] != '\0' && len_dest + j < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dest + len_src);
}
