/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:50:11 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/23 06:10:11 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	malloc_array(mlx_window *map)
{
	int	i;
	
	i = 0;
	map->array = ft_calloc(map->map_y + 1, sizeof(int *));
	if (!map->array)
		print_error("Aled in map array", map);
	while (i < map->map_y)
	{
		map->array[i] = ft_calloc(map->map_x , sizeof(int));
		if (!map->array[i])
			print_error("Aled 2 in map array", map);
		i++;
	}
	map->array[i] = NULL;
}

void	fill_map(mlx_window *map)
{
	int	x;
	int	y;

	y = 0;
	close(map->fd);
	map->fd = open(map->path, O_RDONLY);
	while (y < map->map_y)
	{
		if (map->buf)
			free(map->buf);
		map->buf = get_next_line(map->fd);
		x = 0;
		while (x < map->map_x)
		{
			if (map->buf[x] == '1')
				map->array[y][x] = 1;
			else if (map->buf[x] == '0')
				map->array[y][x] = 5;
			else if (map->buf[x] == 'P')
				map->array[y][x] = 2;
			else if (map->buf[x] == 'C')
				map->array[y][x] = 3;
			else if (map->buf[x] == 'E')
				map->array[y][x] = 4;
			x++;
		}
		y++;
	}
	map->error = 0;
	while (map->error == 0)
	{
		if (map->buf)
		{
			free(map->buf);
			map->buf = NULL;
		}
		else
			break ;
		map->buf = get_next_line(map->fd);
	}
}
