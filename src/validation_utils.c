/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:58:20 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/30 17:58:23 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

int	no_bullshit_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr("PCE01", map->map[i][j]))
				message_error_exit("Error: map has forbidden char\n");
			j++;
		}
		i++;
	}
	return (0);
}

void	has_pce(t_map *map)
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
			if (map->map[i][j] == 'P')
				set_point(map, 'P', j, i);
			if (map->map[i][j] == 'E')
				set_point(map, 'E', j, i);
			if (map->map[i][j] == 'C')
				map->c_count++;
			j++;
		}
		i++;
	}
	if (map->e_flag != 1 || map->p_flag != 1 || map->c_count == 0)
		message_error_exit("Error: wrong number of Ps, Es or Cs\n");
}

void	set_point(t_map *map, char point_kind, size_t x, int y)
{
	if (point_kind == 'P')
	{
		map->p_flag++;
		map->player_p.x = x;
		map->player_p.y = y;
	}
	if (point_kind == 'E')
	{
		map->e_flag++;
		map->exit_p.x = x;
		map->exit_p.y = y;
	}	
}
