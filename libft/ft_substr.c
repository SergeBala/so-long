/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:20:30 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/26 21:20:35 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strncpy_sub(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*ptr;
	size_t	real_len;
	int		i;

	i = start;
	real_len = 0;
	ptr = 0;
	if (!s || len >= SIZE_MAX)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (s[i] != '\0')
	{
		i++;
		real_len++;
	}
	real_len++;
	if (real_len > len)
		real_len = len;
	ptr = (char *)malloc((real_len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strncpy_sub(ptr, s + start, real_len);
	return (ptr);
}
