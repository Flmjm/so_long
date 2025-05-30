/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:10:40 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/30 01:25:07 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_map_params(t_mlx_window *params)
{
	if_ext_ok(params);
	params->fd = open(params->path, O_RDONLY);
	if (params->fd < 1)
		print_error("No file", params);
	check_line(params);
	check_map_wall(params);
	check_map_error(params);
	params->buf = get_next_line(params->fd);
	free(params->buf);
	malloc_array(params);
	fill_map(params);
	is_map_playable(params);
	return (params);
}

void	*check_line(t_mlx_window *params)
{
	int	i;
	int	j;

	j = 0;
	while (params->buf || params->init == 1)
	{
		j++;
		i = 0;
		params->buf = get_next_line(params->fd);
		if (!params->buf)
			break ;
		while (params->buf[i])
		{
			if (params->buf[i] == '\n')
				break ;
			fill_param(params->buf[i], params, i, j);
			i++;
		}
		if (params->map_x != i && params->map_x != 0)
			print_error("Invalid map format", params);
		params->map_x = i;
		params->map_y = j;
		free(params->buf);
	}
	return (params);
}

void	*fill_param(char c, t_mlx_window *params, int x, int y)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'C' && c != 'P')
		print_error("Not a valid character in map", params);
	if (c == 'P')
	{
		params->p_nbr++;
		params->x_player = x;
		params->y_player = y - 1;
	}
	if (c == 'E')
		params->e_nbr++;
	if (c == 'C')
		params->c_nbr++;
	return (params);
}

void	check_map_wall(t_mlx_window *params)
{
	int	x;
	int	y;

	y = 0;
	close(params->fd);
	params->fd = open(params->path, O_RDONLY);
	params->init = 1;
	while (y < params->map_y)
	{
		x = 0;
		free(params->buf);
		params->buf = NULL;
		params->buf = get_next_line(params->fd);
		while (x < params->map_x)
		{
			if ((y == 0 || y == params->map_y - 1) && params->buf[x] != '1')
				print_error("Open map not allowed", params);
			else if ((x == 0 || x == params->map_x - 1)
				&& params->buf[x] != '1')
				print_error("Open map not allowed", params);
			x++;
		}
		y++;
	}
	kill_process(params);
}

void	check_flood_fill(t_mlx_window *params, t_mlx_window *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < params->map_y)
	{
		x = 0;
		while (x < params->map_x)
		{
			if (params->array[y][x] != 1 && params->array[y][x] != 9)
			{
				if (params->array[y][x] != 5)
				{
					free_array(params);
					free_array(map);
					print_error("Exit or collectible are unreachable!", params);
				}
			}
			x++;
		}
		y++;
	}
	free_array(params);
}
