/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:49:44 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/05 17:13:03 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_hook(mlx_window *params)
{
	mlx_hook(params->window, 17, 0, free_mlx, params);
	mlx_hook(params->window, 2, 1, handle_key, params);
	mlx_hook(params->window, 25, 0, resize_window, params);
}

int	handle_key(int keycode, mlx_window *params)
{
	params->old_x_player = params->x_player;
	params->old_y_player = params->y_player;
	params->count_movement += 1;
	if (keycode == 65307)
		free_mlx(params);
	else if (keycode == 65362)
		params->y_player += -32;
	else if (keycode == 65364)
		params->y_player += 32;
	else if (keycode == 65363)
		params->x_player += 32;
	else if (keycode == 65361)
		params->x_player += -32;
	refresh_character(params);
	return (0);
}

int	resize_window(int new_size_y, int new_size_x, mlx_window *params)
{
	params->x_window = new_size_x;
	params->y_window = new_size_y;
	return (0);
}
