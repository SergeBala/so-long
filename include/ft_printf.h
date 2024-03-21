/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:56:12 by sbalasho          #+#    #+#             */
/*   Updated: 2023/02/16 18:56:20 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define  FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putnbr_(int n);
void	ft_putchar_(char c);
int		ft_printf(const char *str, ...);
int		ft_dig_counter_base(int nb, int base);
int		ft_varg_c(va_list arg_p);
int		ft_varg_id_nb(va_list arg_p);
int		ft_varg_str(va_list arg_p);
int		put_u_nb(unsigned int nb, int d_count);
int		put_x_nb(unsigned long long nb, char format, int d_count);
int		ft_varg_u(va_list arg_p);
int		ft_varg_hex(va_list arg_p, char format);
int		ft_varg_ptr(va_list	arg_p);
int		ft_arg_reader(va_list arg_p, char format, int ch_count);

#endif