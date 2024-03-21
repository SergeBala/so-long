/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:56:18 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/27 17:56:22 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_s_len;
	size_t	s1_len;
	size_t	s2_len;
	void	*ptr;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s_len = s1_len + s2_len;
	ptr = (char *)malloc((new_s_len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strcpy(ptr, s1);
	ft_strcpy((char *)(&ptr[s1_len]), s2);
	return (ptr);
}
