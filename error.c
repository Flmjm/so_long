/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:37:49 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/12 23:42:13 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_error(mlx_window *params)
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

void	print_error(char *error, mlx_window *params)
{
	kill_process(params);
	ft_printf("Error\n%s", error);
	exit (-1);
}
void	kill_process(mlx_window *map)
{
	if (map->buf)
		free(map->buf);
	map->buf = NULL;
	
}
