/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:10:40 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/12 23:40:54 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_ext_ok(mlx_window *params)
{
	int	i;
	int	ok;
	
	ok = 0;
	i = 0;
	i = ft_strlen(params->path);
	if (i > 4)
		i = i - 4;
	ok = ft_strncmp(&params->path[i], ".ber", 4);
	if (ok != 0)
		print_error("Map is not a .ber", params);
}

void	*get_map_params(mlx_window *params)
{
	if_ext_ok(params);
	init_map(params);
	params->fd = open(params->path, O_RDONLY);
	if (params->fd < 1)
		print_error("No file", params);
	check_line(params);
	check_map_wall(params);
	check_map_error(params);
	params->buf = get_next_line(params->fd);
	free(params->buf);
	// start alloc -----------------------------------------------
	malloc_array(params);
	fill_map(params);
	return (params);
}

void	*check_line(mlx_window *params)
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
			fill_param(params->buf[i], params);
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

void	*fill_param(char c, mlx_window *params)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'C' && c != 'P')
		print_error("Not a valid character in map", params);
	if (c == 'P')
		params->p_nbr++;
	if (c == 'E')
		params->e_nbr++;
	if (c == 'C')
		params->c_nbr++;
	return (params);
}

void	check_map_wall(mlx_window *params)
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
		params->init++;
		while (x < params->map_x)
		{
			if ((y == 0 || y == params->map_y - 1) && params->buf[x] != '1')
				print_error("Open map not allowed", params);
			else if ((x == 0 || x == params->map_x - 1) && params->buf[x] != '1')
				print_error("Open map not allowed", params);
			x++;
		}
		y++;
	}
	kill_process(params);
}
