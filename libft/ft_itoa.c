/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:12:28 by sbalasho          #+#    #+#             */
/*   Updated: 2023/02/01 12:12:33 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_dig_counter(int nb)
{
	int	dig_count;
	int	tmp_nb;

	dig_count = 0;
	if (nb == 0)
		return (1);
	tmp_nb = nb;
	while (tmp_nb != 0)
	{
		tmp_nb = tmp_nb / 10;
		dig_count++;
	}
	if (nb < 0)
		dig_count++;
	return (dig_count);
}

static int	ft_power(int nb, int power)
{
	int	i;
	int	res;

	i = power;
	res = nb;
	if (power == 0)
		return (1);
	if ((nb == 0 && power != 0) || power < 0)
		return (0);
	else
	{
		while (i > 1)
		{
			res = res * nb;
			i--;
		}
		return (res);
	}	
}

static char	*ft_ar_fill(char *res_ptr, int i, int n, int dig_count)
{
	while (dig_count)
	{
		res_ptr[i] = (n / ft_power(10, dig_count - 1)) + 48;
		n = n % ft_power(10, dig_count - 1);
		dig_count--;
		i++;
	}
	res_ptr[i] = '\0';
	return (res_ptr);
}

char	*ft_itoa(int n)
{
	int		i;
	int		dig_count;
	char	*res_ptr;

	i = 0;
	dig_count = ft_dig_counter(n);
	res_ptr = (char *)malloc((dig_count + 1) * sizeof(char));
	if (!res_ptr)
		return (0);
	if (n == -2147483648)
	{
		ft_strlcpy(res_ptr, "-2147483648", 12);
		return (res_ptr);
	}
	if (n < 0 && n > -2147483648)
	{
		res_ptr[i] = '-';
		dig_count--;
		n = n * (-1);
		i++;
	}
	ft_ar_fill(res_ptr, i, n, dig_count);
	return (res_ptr);
}
