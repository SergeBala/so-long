/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:09:22 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/26 20:09:27 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t numb, size_t size)
{
	void	*ptr;

	if ((numb && size) && (numb * size < numb || numb * size < size))
		return (0);
	ptr = malloc(numb * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, numb * size);
	return (ptr);
}
