/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:07:34 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/26 12:07:39 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1_ch;
	unsigned char	*s2_ch;

	i = 0;
	s1_ch = (unsigned char *)s1;
	s2_ch = (unsigned char *)s2;
	while (s1_ch && s2_ch && s1_ch[i] == s2_ch[i] && n > 1)
	{
		i++;
		n--;
	}		
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (s1_ch[i] - s2_ch[i]);
	}
}
