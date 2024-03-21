/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:42:12 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/26 16:42:16 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*s_char;

	i = 0;
	ch = (unsigned char)c;
	s_char = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (i <= n - 1)
	{
		if (*(s_char + i) == ch)
			return ((void *)(s_char + i));
		i++;
	}
	return (0);
}
