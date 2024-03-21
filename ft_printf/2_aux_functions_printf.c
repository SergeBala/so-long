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

int	put_x_nb(unsigned long long nb, char format, int d_count)
{
	if (format == 'X' || format == 'x')
		nb = (unsigned int)nb;
	if (nb >= 16)
	{
		d_count = d_count + put_x_nb(nb / 16, format, d_count);
	}
	if (nb % 16 < 10)
	{
		ft_putchar_(nb % 16 + 48);
		d_count++;
	}
	if (nb % 16 >= 10)
	{
		if (format == 'X')
			ft_putchar_(nb % 16 + 55);
		if (format == 'x' || format == 'p')
			ft_putchar_(nb % 16 + 87);
		d_count++;
	}
	return (d_count);
}

int	ft_varg_u(va_list arg_p)
{
	unsigned int	current;

	current = va_arg(arg_p, unsigned int);
	return (put_u_nb(current, 0));
}

int	ft_varg_hex(va_list arg_p, char format)
{
	unsigned long long	current;
	int					d_count;

	d_count = 0;
	current = va_arg(arg_p, unsigned long long);
	return (put_x_nb(current, format, d_count));
}

int	ft_varg_ptr(va_list	arg_p)
{
	unsigned long long	current;
	int					d_count;

	d_count = 0;
	current = va_arg(arg_p, unsigned long long);
	write(1, "0x", 2);
	return (put_x_nb(current, 'p', d_count) + 2);
}
