/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:48:06 by sbalasho          #+#    #+#             */
/*   Updated: 2023/08/14 09:48:09 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

void	move_left(t_map *map)
{
	if (map->map[map->player_p.y][map->player_p.x - 1] == 'C')
		map->c_count--;
	if (map->player_p.y == map->exit_p.y && map->player_p.x == map->exit_p.x)
		map->map[map->player_p.y][map->player_p.x] = 'E';
	else
		map->map[map->player_p.y][map->player_p.x] = '0';
	if (map->map[map->player_p.y][map->player_p.x - 1] == 'E')
		map->map[map->player_p.y][map->player_p.x - 1] = 'B';
	else
		map->map[map->player_p.y][map->player_p.x - 1] = 'P';
	map->player_p.x--;
	map->move_count++;
	ft_printf("move counter: %i\n", map->move_count);
}

void	move_right(t_map *map)
{
	if (map->map[map->player_p.y][map->player_p.x + 1] == 'C')
		map->c_count--;
	if (map->player_p.y == map->exit_p.y && map->player_p.x == map->exit_p.x)
		map->map[map->player_p.y][map->player_p.x] = 'E';
	else
		map->map[map->player_p.y][map->player_p.x] = '0';
	if (map->map[map->player_p.y][map->player_p.x + 1] == 'E')
		map->map[map->player_p.y][map->player_p.x + 1] = 'B';
	else
		map->map[map->player_p.y][map->player_p.x + 1] = 'P';
	map->player_p.x++;
	map->move_count++;
	ft_printf("move counter: %i\n", map->move_count);
}

void	move_up(t_map *map)
{
	if (map->map[map->player_p.y - 1][map->player_p.x] == 'C')
		map->c_count--;
	if (map->player_p.y == map->exit_p.y && map->player_p.x == map->exit_p.x)
		map->map[map->player_p.y][map->player_p.x] = 'E';
	else
		map->map[map->player_p.y][map->player_p.x] = '0';
	if (map->map[map->player_p.y - 1][map->player_p.x] == 'E')
		map->map[map->player_p.y - 1][map->player_p.x] = 'B';
	else
		map->map[map->player_p.y - 1][map->player_p.x] = 'P';
	map->player_p.y--;
	map->move_count++;
	ft_printf("move counter: %i\n", map->move_count);
}

void	move_down(t_map *map)
{
	if (map->map[map->player_p.y + 1][map->player_p.x] == 'C')
		map->c_count--;
	if (map->player_p.y == map->exit_p.y && map->player_p.x == map->exit_p.x)
		map->map[map->player_p.y][map->player_p.x] = 'E';
	else
		map->map[map->player_p.y][map->player_p.x] = '0';
	if (map->map[map->player_p.y + 1][map->player_p.x] == 'E')
		map->map[map->player_p.y + 1][map->player_p.x] = 'B';
	else
		map->map[map->player_p.y + 1][map->player_p.x] = 'P';
	map->player_p.y++;
	map->move_count++;
	ft_printf("move counter: %i\n", map->move_count);
}
