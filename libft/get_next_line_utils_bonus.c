/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:06:44 by sbalasho          #+#    #+#             */
/*   Updated: 2023/03/09 13:06:48 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_new_substr(char *s, unsigned int start, size_t len)
{
	void	*ptr;
	size_t	real_len;
	int		i;

	i = start;
	real_len = 0;
	ptr = 0;
	if (!s || len >= SIZE_MAX)
		return (0);
	while (s[i] != '\0')
	{
		i++;
		real_len++;
	}
	if (real_len > len)
		real_len = len;
	ptr = (char *)malloc((real_len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_new_strlcpy(ptr, s + start, real_len + 1);
	return (ptr);
}

int	is_a_line(char *str)
{
	int	i;

	if (!str)
		return (-2);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_new_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_new_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize != 0)
	{	
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}

char	*ft_new_strjoin(char *s1, char *s2)
{
	size_t	new_s_len;
	size_t	s1_len;
	size_t	s2_len;
	void	*ptr;

	s1_len = ft_new_strlen(s1);
	s2_len = ft_new_strlen(s2);
	new_s_len = s1_len + s2_len;
	ptr = (char *)malloc((new_s_len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (s1)
		ft_new_strlcpy(ptr, s1, s1_len + 1);
	ft_new_strlcpy(ptr + s1_len, s2, s2_len +1);
	return (ptr);
}
