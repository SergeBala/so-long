/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:26:45 by sbalasho          #+#    #+#             */
/*   Updated: 2023/07/19 17:26:49 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

void	function_fail(char *line, char *func)
{
	ft_putstr_fd("line ", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(func, 2);
	perror(" failed!");
	exit(1);
}

void	message_error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

int	free_double_char_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (1);
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (0);
}

int	print_double_char_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (1);
	while (arr && arr[i])
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
	return (0);
}

int	check_if_empty(char *big_str)
{
	int	i;

	i = 0;
	if (!*big_str)
		message_error_exit("map is empty!\n");
	while (big_str[i])
	{
		if (big_str[i] != '\n')
			return (0);
		i++;
	}
	message_error_exit("map is empty except for new lines!\n");
	return (1);
}
