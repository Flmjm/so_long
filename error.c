/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:37:49 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/30 01:28:13 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_error(t_mlx_window *params)
{
	if (params->p_nbr == 0)
		print_error("No spawn point", params);
	if (params->map_x == params->map_y)
		print_error("Map is not a rectangle", params);
	if (params->e_nbr != 1)
		print_error("Only one exit need", params);
	if (params->c_nbr < 1)
		print_error("Need at least one collectible", params);
}

void	print_error(char *error, t_mlx_window *params)
{
	if (params)
		kill_process(params);
	ft_printf("Error\n%s", error);
	exit (-1);
}

void	kill_process(t_mlx_window *map)
{
	close(map->fd);
	open(map->path, O_RDONLY);
	if (map->buf)
	{
		free(map->buf);
	}
	while (map->buf)
	{
		map->buf = get_next_line(map->fd);
		free(map->buf);
	}
}

void	copy_value_for_check(t_mlx_window *map, t_mlx_window *cpy)
{
	cpy->map_x = map->map_x;
	cpy->map_y = map->map_y;
	cpy->buf = NULL;
	cpy->error = map->error;
	cpy->init = map->init;
	cpy->fd = map->fd;
	cpy->path = map->path;
}
