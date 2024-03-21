/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:30:30 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/26 11:30:35 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static int	check_sign(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-')
	{
		i++;
		i *= -1;
		return (i);
	}
	if (str[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	j;
	int	numb;
	int	minus;

	j = check_sign(str);
	numb = 0;
	minus = 1;
	if (j < 0)
	{
		j *= -1;
		minus = -1;
	}
	if (!(str[j] >= 48 && str[j] <= 57))
		return (0);
	while (str[j] >= 48 && str[j] <= 57)
	{
		numb *= 10;
		numb = numb + str[j] - 48;
		j++;
	}
	return (numb * minus);
}
