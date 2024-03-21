/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:38:25 by sbalasho          #+#    #+#             */
/*   Updated: 2023/05/28 15:41:06 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define KEY_ESC 53
# define PIC_SIZE 48
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define COLOR_M 0x0000FF

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_point
{
	size_t	x;
	int		y;
}	t_point;

typedef struct s_fill
{
	int		c_count;
	int		exit_reached_flag;
	int		success_flag;
}	t_fill;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*p_img;
	void	*e_img;
	void	*c_img;
	void	*b_img;
	void	*w_img;
}	t_mlx;

typedef struct s_map
{
	int		c_count;
	int		p_flag;
	int		e_flag;
	int		move_count;
	size_t	width;
	int		line_count;
	char	**map;
	t_point	player_p;
	t_point	exit_p;
	t_mlx	g_mlx;

}	t_map;

int		free_double_char_arr(char **arr);
int		print_double_char_arr(char **arr);
void	function_fail(char *line, char *func);
void	map_allocator(char *map_file, t_map *map, int *fd);
void	map_validator(t_map *map);
void	map_vars_initiator(t_map **map);
void	message_error_exit(char *message);
int		no_double_new_line(char *str);
int		check_if_ber(char *str);
int		no_bullshit_chars(t_map *map);
void	has_pce(t_map *map);
void	set_point(t_map *map, char point_kind, size_t x, int y);
void	is_rectang(t_map *map);
void	has_walls(t_map	*map);
char	**double_char_dup(char **arr);
void	path_fill(char **test, t_point map_size, t_point curr, t_fill *c);
void	has_valid_path(t_map *map);
void	game_launch(t_map *map);
int		esc_press(int keycode, t_mlx *g_mlx);
int		red_cross(t_mlx *g_mlx);
void	put_map_on_screen(t_map *map, t_mlx g_mlx);
void	map_printer(t_map *map, t_mlx g_mlx, int i, size_t j);
void	map_printer_two(t_map *map, t_mlx g_mlx, int i, size_t j);
int		game_play(int key, t_map *map);
int		game_over(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
int		check_if_empty(char *big_str);
#endif
