/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <sbalasho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:03:33 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/29 15:45:01 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

void	map_allocator(char *map_file, t_map *map, int *fd)
{
	char	*big_str;
	char	*tmp;
	char	*tmp2;

	*fd = open(map_file, O_RDONLY);
	if ((*fd) < 0)
		function_fail("68", "open");
	big_str = ft_calloc(1, sizeof(char));
	while (1)
	{
		tmp = get_next_line(*fd);
		if (!tmp)
			break ;
		tmp2 = ft_strdup(big_str);
		free(big_str);
		big_str = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
	}
	check_if_empty(big_str);
	no_double_new_line(big_str);
	map->map = ft_split(big_str, '\n');
	free(big_str);
}

void	map_validator(t_map *map)
{
	map_vars_initiator(&map);
	no_bullshit_chars(map);
	is_rectang(map);
	has_walls(map);
	has_pce(map);
	has_valid_path(map);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		fd;

	if (ac != 2)
		message_error_exit("Error: wrong number of arguments!\n");
	check_if_ber(av[1]);
	map_allocator(av[1], &map, &fd);
	map_validator(&map);
	game_launch(&map);
	free_double_char_arr(map.map);
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	// mlx_loop(mlx);
// }

// printf("player coordinates: x:%zu, y:%i, exit coordinates: 
// x:%zu, y:%i\n", map.player_p.x, map.player_p.y, map.exit_p.x, map.exit_p.y);
