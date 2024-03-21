/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:09:52 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/25 17:10:00 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		y;
	char	ch;

	y = ft_strlen(s);
	ch = (char)c;
	while (y >= 0)
	{
		if (*(s + y) == ch)
			return ((char *)(s + y));
		y--;
	}
	return (0);
}
