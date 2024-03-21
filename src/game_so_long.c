/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:15:21 by sbalasho          #+#    #+#             */
/*   Updated: 2023/08/04 14:15:25 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

void	game_launch(t_map *map)
{
	int		pic_w;
	int		pic_h;

	map->g_mlx.mlx = mlx_init();
	map->g_mlx.win = mlx_new_window(map->g_mlx.mlx, (PIC_SIZE * (map->width)),
			(PIC_SIZE * (map->line_count)), "Collect the goodies and get out!");
	map->g_mlx.p_img = mlx_xpm_file_to_image(map->g_mlx.mlx,
			"./img/zerk.xpm", &pic_w, &pic_h);
	map->g_mlx.e_img = mlx_xpm_file_to_image(map->g_mlx.mlx,
			"./img/door.xpm", &pic_w, &pic_h);
	map->g_mlx.c_img = mlx_xpm_file_to_image(map->g_mlx.mlx,
			"./img/c0.xpm", &pic_w, &pic_h);
	map->g_mlx.w_img = mlx_xpm_file_to_image(map->g_mlx.mlx,
			"./img/walls.xpm", &pic_w, &pic_h);
	map->g_mlx.b_img = mlx_xpm_file_to_image(map->g_mlx.mlx,
			"./img/background.xpm", &pic_w, &pic_h);
	mlx_hook(map->g_mlx.win, 2, 1, esc_press, &(map->g_mlx));
	mlx_hook(map->g_mlx.win, 17, 1, red_cross, &(map->g_mlx));
	put_map_on_screen(map, map->g_mlx);
	mlx_key_hook(map->g_mlx.win, game_play, map);
	mlx_loop(map->g_mlx.mlx);
}

void	put_map_on_screen(t_map *map, t_mlx g_mlx)
{
	int		i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	while (i < map->line_count)
	{
		j = 0;
		while (j < map->width)
		{
			map_printer(map, g_mlx, i, j);
			j++;
		}
		i++;
	}
	str = ft_itoa(map->move_count);
	mlx_string_put(map->g_mlx.mlx, map->g_mlx.win,
		50, 12, COLOR_M, "move counter: ");
	mlx_string_put(map->g_mlx.mlx, map->g_mlx.win,
		180, 12, COLOR_M, str);
	free(str);
}

void	map_printer(t_map *map, t_mlx g_mlx, int i, size_t j)
{
	if (map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.b_img, j * PIC_SIZE, i * PIC_SIZE);
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.p_img, j * PIC_SIZE, i * PIC_SIZE);
	}
	else if (map->map[i][j] == 'B')
	{
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.e_img, j * PIC_SIZE, i * PIC_SIZE);
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.p_img, j * PIC_SIZE, i * PIC_SIZE);
	}
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.e_img, j * PIC_SIZE, i * PIC_SIZE);
	else
		map_printer_two(map, g_mlx, i, j);
}

void	map_printer_two(t_map *map, t_mlx g_mlx, int i, size_t j)
{
	if (map->map[i][j] == 'C')
	{
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.b_img, j * PIC_SIZE, i * PIC_SIZE);
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.c_img, j * PIC_SIZE, i * PIC_SIZE);
	}
	if (map->map[i][j] == '0')
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.b_img, j * PIC_SIZE, i * PIC_SIZE);
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win,
			g_mlx.w_img, j * PIC_SIZE, i * PIC_SIZE);
}

int	game_play(int key, t_map *map)
{
	if (key == KEY_LEFT
		&& map->map[map->player_p.y][map->player_p.x - 1] != '1')
		move_left(map);
	if (key == KEY_RIGHT
		&& map->map[map->player_p.y][map->player_p.x + 1] != '1')
		move_right(map);
	if (key == KEY_UP
		&& map->map[map->player_p.y - 1][map->player_p.x] != '1')
		move_up(map);
	if (key == KEY_DOWN
		&& map->map[map->player_p.y + 1][map->player_p.x] != '1')
		move_down(map);
	put_map_on_screen(map, map->g_mlx);
	game_over(map);
	return (0);
}

	// unsigned long long	i;

	// i = 0;