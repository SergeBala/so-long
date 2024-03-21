/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:44:57 by sbalasho          #+#    #+#             */
/*   Updated: 2023/07/07 16:45:00 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

void	map_vars_initiator(t_map **map)
{
	(*map)->c_count = 0;
	(*map)->p_flag = 0;
	(*map)->e_flag = 0;
	(*map)->width = 0;
	(*map)->line_count = 0;
	(*map)->move_count = 0;
}

void	has_valid_path(t_map *map)
{
	char	**test;
	t_point	map_size;
	t_fill	flags;

	test = double_char_dup(map->map);
	map_size.x = map->width;
	map_size.y = map->line_count;
	flags.c_count = map->c_count;
	flags.success_flag = 0;
	flags.exit_reached_flag = 0;
	path_fill(test, map_size, map->player_p, &flags);
	if (flags.success_flag == 0)
		message_error_exit("Error: no valid path!\n");
	free_double_char_arr(test);
}

void	path_fill(char **test, t_point map_size, t_point curr, t_fill *c)
{
	if (curr.x < 0 || curr.x >= map_size.x
		|| curr.y < 0 || curr.y >= map_size.y)
		return ;
	if (test[curr.y][curr.x] == '1' || test[curr.y][curr.x] == '.')
		return ;
	if (test[curr.y][curr.x] == 'E')
	{
		c->exit_reached_flag = 1;
	}
	if (test[curr.y][curr.x] == 'C')
		c->c_count--;
	test[curr.y][curr.x] = '.';
	if (c->exit_reached_flag == 1 && c->c_count == 0)
	{
		c->success_flag = 1;
		return ;
	}
	path_fill(test, map_size, (t_point){curr.x, curr.y - 1}, c);
	path_fill(test, map_size, (t_point){curr.x, curr.y + 1}, c);
	path_fill(test, map_size, (t_point){curr.x - 1, curr.y}, c);
	path_fill(test, map_size, (t_point){curr.x + 1, curr.y}, c);
}

char	**double_char_dup(char **arr)
{
	int		i;
	char	**res_ptr;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	res_ptr = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (arr[i])
	{
		res_ptr[i] = ft_strdup(arr[i]);
		i++;
	}
	res_ptr[i] = 0;
	return (res_ptr);
}

// print_double_char_arr(test);
