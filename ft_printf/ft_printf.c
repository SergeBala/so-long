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

int	ft_arg_reader(va_list arg_p, char format, int ch_count)
{
	if (format == '%')
	{	
		ft_putchar_('%');
		ch_count++;
	}
	else if (format == 'c')
		ch_count = ch_count + ft_varg_c(arg_p);
	else if (format == 'i' || format == 'd')
		ch_count = ch_count + ft_varg_id_nb(arg_p);
	else if (format == 'p')
		ch_count = ch_count + ft_varg_ptr(arg_p);
	else if (format == 's')
		ch_count = ch_count + ft_varg_str(arg_p);
	else if (format == 'X')
		ch_count = ch_count + ft_varg_hex(arg_p, format);
	else if (format == 'x')
		ch_count = ch_count + ft_varg_hex(arg_p, format);
	else if (format == 'u')
		ch_count = ch_count + ft_varg_u(arg_p);
	else
	{	
		ft_putchar_(format);
		ch_count++;
	}
	return (ch_count);
}

int	ft_printf(const char *str, ...)
{
	int		i;	
	int		ch_count;
	va_list	arg_p;

	if (!str)
		return (0);
	i = 0;
	ch_count = 0;
	va_start(arg_p, str);
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar_(str[i]);
			ch_count++;
			i++;
		}
		if (str[i] == '\0' || (str[i] == '%' && str[i + 1] == '\0'))
			return (ch_count);
		i++;
		ch_count += ft_arg_reader(arg_p, str[i], 0);
		i++;
	}
	return (ch_count);
}
