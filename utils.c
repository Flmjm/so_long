/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:49:29 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/12 23:34:32 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_character(mlx_window *params)
{
	check_position_player(params);
	mlx_put_image_to_window(params->mlx, params->window, params->character_texture, params->x_player, params->y_player);
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
		mlx_destroy_image(params->mlx, params->character_texture);
		mlx_destroy_image(params->mlx, params->coin_texture);
		mlx_destroy_image(params->mlx, params->exit_texture);
		mlx_destroy_image(params->mlx, params->wall_texture);
		mlx_destroy_image(params->mlx, params->background_texture);
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
	int	x;
	int	y;

	y = 0;
	while (y < params->map_y)
	{
		free(params->array[y]);
		y++;
	}
	free(params->array);
}
