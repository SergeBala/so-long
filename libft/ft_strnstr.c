/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:55:19 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/20 15:03:52 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (!str && n == 0)
		return (0);
	if (to_find[0] == '\0')
		return ((char *)(str));
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] == str[i + j] && (i + j) < n)
			{
				if (to_find[j + 1] == '\0')
					return ((char *)(&str[i]));
				j++;
			}
		}
		i++;
	}
	return (0);
}
