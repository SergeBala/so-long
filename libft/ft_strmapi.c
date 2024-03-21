/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:27:24 by sbalasho          #+#    #+#             */
/*   Updated: 2023/02/01 18:27:37 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res_ptr;
	size_t	s_len;
	size_t	i;

	if (!s || !f)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	res_ptr = (char *)malloc((s_len + 1) * sizeof(char));
	if (!res_ptr)
		return (0);
	while (i < s_len)
	{
		res_ptr[i] = (*f)(i, s[i]);
		i++;
	}
	res_ptr[i] = '\0';
	return (res_ptr);
}
