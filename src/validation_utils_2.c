/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:27:35 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/30 20:27:41 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

int	check_if_ber(char *str)
{
	if (ft_strncmp(str + (ft_strlen(str) - 4), ".ber", 4))
		message_error_exit("Error: map is not .ber!\n");
	return (0);
}

int	no_double_new_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(str, "\n");
	while (tmp && tmp[i] && tmp[i + 1])
	{
		if (tmp[i] == '\n' && tmp[i + 1] == '\n')
		{
			free(tmp);
			message_error_exit("Error: map broken, split in the middle\n");
		}
		i++;
	}
	free(tmp);
	return (0);
}

void	is_rectang(t_map *map)
{
	int	i;

	i = 0;
	map->width = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		map->line_count++;
		if (map->width != ft_strlen(map->map[i]))
			message_error_exit("Error: map not rectangular!\n");
		i++;
	}
	if (map->width > 28 || map->line_count > 18)
		message_error_exit("Error: map too big\n");
}

void	has_walls(t_map	*map)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if ((i == 0 || i == map->line_count - 1) && map->map[i][j] != '1')
				message_error_exit("Error: broken wall at top or bottom\n");
			if ((j == 0 || j == (map->width - 1)) && map->map[i][j] != '1')
				message_error_exit("Error: broken wall left or right\n");
			j++;
		}
		i++;
	}
}
