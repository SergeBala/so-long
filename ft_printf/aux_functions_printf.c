/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:33:59 by sbalasho          #+#    #+#             */
/*   Updated: 2023/02/09 17:34:03 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_dig_counter_base(int nb, int base)
{
	int	dig_count;
	int	tmp_nb;

	dig_count = 0;
	if (nb == 0)
		return (1);
	tmp_nb = nb;
	while (tmp_nb != 0)
	{
		tmp_nb = tmp_nb / base;
		dig_count++;
	}
	if (nb < 0)
		dig_count++;
	return (dig_count);
}

int	ft_varg_c(va_list arg_p)
{
	int	current;	

	current = va_arg(arg_p, int);
	ft_putchar_(current);
	return (1);
}

int	ft_varg_id_nb(va_list arg_p)
{
	int	current;

	current = va_arg(arg_p, int);
	ft_putnbr_(current);
	return (ft_dig_counter_base(current, 10));
}

int	ft_varg_str(va_list arg_p)
{
	int		i;
	char	*s_ptr;

	i = 0;
	s_ptr = va_arg(arg_p, char *);
	if (!s_ptr)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s_ptr[i] != '\0')
	{
		write(1, &s_ptr[i], 1);
		i++;
	}
	return (i);
}

int	put_u_nb(unsigned int nb, int d_count)
{
	if (nb >= 10)
		d_count = d_count + put_u_nb(nb / 10, d_count);
	ft_putchar_(nb % 10 + 48);
	d_count++;
	return (d_count);
}
