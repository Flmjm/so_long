/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:49:29 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/23 06:09:37 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_character(mlx_window *params)
{
	check_position_player(params);
	if (params->is_jumping == 1)
	{
		if (params->player_direction == 6)
			mlx_put_image_to_window(params->mlx, params->window, params->character_fall_texture_left, params->x_player, params->y_player);
		else
			mlx_put_image_to_window(params->mlx, params->window, params->character_fall_texture_right, params->x_player, params->y_player);
	}
	else
	{
		if (params->player_direction == 6)
			mlx_put_image_to_window(params->mlx, params->window, params->character_texture_left, params->x_player, params->y_player);
		else
			mlx_put_image_to_window(params->mlx, params->window, params->character_texture_right, params->x_player, params->y_player);
	}
}

void	check_position_player(mlx_window *params)
{
	if (params->array[params->y_player / TEXTURE_SIZE][params->x_player / TEXTURE_SIZE] == 1)
	{
		params->x_player = params->old_x_player;
		params->y_player = params->old_y_player;
	}
	refresh(params);
}

int free_mlx(mlx_window *params)
{
	if (params->window)
	{
		mlx_destroy_window(params->mlx, params->window);
		mlx_destroy_image(params->mlx, params->character_fall_texture_left);
		mlx_destroy_image(params->mlx, params->coin_texture);
		mlx_destroy_image(params->mlx, params->exit_texture);
		mlx_destroy_image(params->mlx, params->coin_texture_2);
		mlx_destroy_image(params->mlx, params->exit_open_texture);
		mlx_destroy_image(params->mlx, params->wall_texture);
		mlx_destroy_image(params->mlx, params->background_texture);
		mlx_destroy_image(params->mlx, params->character_fall_texture_right);
		mlx_destroy_image(params->mlx, params->character_texture_right);
		mlx_destroy_image(params->mlx, params->character_texture_left);
	}
	if (params->mlx)
	{	
		mlx_destroy_display(params->mlx);
		free(params->mlx);
	}
	free_array(params);
	exit (0);
}

void	free_array(mlx_window *params)
{
	int	y;

	y = 0;
	while (y < params->map_y)
	{
		free(params->array[y]);
		y++;
	}
	free(params->array);
}
