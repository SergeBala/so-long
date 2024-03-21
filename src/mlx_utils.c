/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:48:51 by sbalasho          #+#    #+#             */
/*   Updated: 2023/08/04 16:48:55 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

int	esc_press(int keycode, t_mlx *g_mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window((*g_mlx).mlx, (*g_mlx).win);
		exit(0);
	}
	return (0);
}

int	red_cross(t_mlx *g_mlx)
{
	mlx_destroy_window((*g_mlx).mlx, (*g_mlx).win);
	exit(0);
}

int	game_over(t_map *map)
{
	if (map->player_p.y == map->exit_p.y
		&& map->player_p.x == map->exit_p.x && map->c_count == 0)
	{
		ft_printf("you've won!\n");
		exit (0);
	}
	return (0);
}
