/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:44:51 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/28 16:45:18 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res_ptr;
	size_t	start_trim;
	size_t	end_trim;

	if (!s1 || !set)
		return (NULL);
	start_trim = 0;
	end_trim = ft_strlen(s1);
	while (ft_strchr(set, s1[start_trim]) && s1[start_trim])
		start_trim++;
	if (start_trim == end_trim)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end_trim - 1]) && end_trim)
		end_trim--;
	res_ptr = ft_substr(s1, start_trim, end_trim - start_trim);
	return (res_ptr);
}
