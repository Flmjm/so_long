/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:49:44 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/23 04:41:28 by mleschev         ###   ########.fr       */
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
		jumping(params);
	else if (keycode == 65364)
		params->is_jumping = 0;
	else if (keycode == 65363)
	{
		params->player_direction = 4;
		params->x_player += TEXTURE_SIZE;
	}
	else if (keycode == 65361)
	{
		params->player_direction = 6;
		params->x_player += -TEXTURE_SIZE;
	}
	refresh_character(params);
	return (0);
}

int	resize_window(int new_size_y, int new_size_x, mlx_window *params)
{
	params->x_window = new_size_x;
	params->y_window = new_size_y;
	return (0);
}

void	jumping(mlx_window *player)
{
	if (player->is_jumping == 0)
	{
		player->is_jumping = 1;
		player->next_frame = 0;
		player->y_player += -TEXTURE_SIZE;
	}
}
