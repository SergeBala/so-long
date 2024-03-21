/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:45:40 by sbalasho          #+#    #+#             */
/*   Updated: 2023/02/03 18:12:26 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static void	free_res_ptr(char **res_ptr, int i)
{
	while (i > 0)
	{
		free(res_ptr[i]);
		i--;
	}
	free(res_ptr[i]);
	res_ptr = 0;
	return ;
}

static char	**null_ing(char **res_ptr)
{
	res_ptr = malloc(1 * sizeof(char *));
	if (!res_ptr)
		return (NULL);
	res_ptr[0] = NULL;
	return (res_ptr);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	w_count;

	i = 0;
	w_count = 0;
	if (!s)
		return (0);
	if (*s != c && *s != '\0')
		w_count++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				w_count++;
		}
		if (!(s[i] == '\0'))
			i++;
	}
	return (w_count);
}

static char	**ft_filler(char **res_ptr, int i, const char *s, char c)
{
	size_t		start;
	size_t		end;
	int			w_count;

	start = 0;
	w_count = ft_word_count(s, c);
	while (w_count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		res_ptr[i] = ft_substr(s, start, end - start);
		if (!res_ptr[i])
		{
			free_res_ptr(res_ptr, i);
			return (res_ptr);
		}
		start = end;
		i++;
		w_count--;
	}
	res_ptr[i] = 0;
	return (res_ptr);
}

char	**ft_split(char const *s, char c)
{	
	char	**res_ptr;

	if (!s || s[0] == '\0')
	{
		res_ptr = 0;
		return (null_ing(res_ptr));
	}
	res_ptr = malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!res_ptr)
		return (NULL);
	return (ft_filler(res_ptr, 0, s, c));
}
