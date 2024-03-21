/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:44:41 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/25 15:44:47 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		y;
	char	ch;

	i = 0;
	y = ft_strlen(s);
	ch = (char)c;
	while (i <= y)
	{
		if (*(s + i) == ch)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
