/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:49:29 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/05 18:12:18 by mleschev         ###   ########.fr       */
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
	if (params->array[params->y_player / 32][params->x_player / 32] == 1)
	{
		params->x_player = params->old_x_player;
		params->y_player = params->old_y_player;
	}
	refresh(params);
	// ft_printf("old x:%d | old y:%d || x:%d | y:%d\n", params->old_x_player / 32, params->old_y_player / 32, params->x_player / 32, params->y_player / 32);
}

int free_mlx(mlx_window *params)
{
	if (params->window)
	{
		mlx_destroy_window(params->mlx, params->window);
		mlx_destroy_image(params->mlx, params->character_texture);
	}
	if (params->mlx)
	{	
		mlx_destroy_display(params->mlx);
		free(params->mlx);
	}
	// free_array(params);
	exit (0);
}

// void	free_array(mlx_window *params)
// {
// 	int i;

// 	i = 0;
// 	while (i < params->map_x)
// 	{
// 		free(params->array[i]);
// 		params->array[i] = NULL;
// 		i++;
// 	}
// }
