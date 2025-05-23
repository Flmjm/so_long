/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:47:37 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/23 05:04:24 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	mlx_window params;	
	// start parse-------------------------------------------
	if (argc > 2)
		print_error("Too much arguments !", NULL);
	else if (argc < 2)
		print_error("Too few arguments !", NULL);
	init_map(&params);
	params.path = argv[1];
	get_map_params(&params);
	init_window(&params);
	// ------------------Start listen--------------------------
	mlx_loop_hook(params.mlx, next_frame, &params);
	mlx_loop(params.mlx);
}

int	next_frame(mlx_window *params)
{
	params->next_frame += 1;
	if (params->array[params->y_player / TEXTURE_SIZE][params->x_player / TEXTURE_SIZE] != 1)
	{
		params->old_x_player = params->x_player;
		params->old_y_player = params->y_player;
	}
	if (params->array[params->y_player / TEXTURE_SIZE][params->x_player / TEXTURE_SIZE] == 4 && (params->c_nbr == params->coin_collected))
		free_mlx(params);
	if (params->next_frame == 20000)
	{
		params->next_frame = 0;
		if (params->array[params->y_player / TEXTURE_SIZE + 1][params->x_player/ TEXTURE_SIZE] != 1)
		{
			params->is_jumping = 1;
			params->y_player += TEXTURE_SIZE;
		}
		else
			params->is_jumping = 0;
	}
		refresh_character(params);
	return (0);
}

void	*init_map(mlx_window *params)
{
	params->mlx = NULL;
	params->window = NULL;
	params->wall_texture = NULL;
	params->coin_texture = NULL;
	params->exit_texture = NULL;
	params->background_texture = NULL;
	params->character_texture_left = NULL;
	params->character_texture_right = NULL;	
	params->x_player = 0;
	params->y_player = 0;
	params->x_window = 0;
	params->y_window = 0;
	params->array = NULL;
	params->c_nbr = 0;
	params->e_nbr = 0;
	params->error = 0;
	params->p_nbr = 0;
	params->buf = NULL;
	params->fd = 0;
	params->map_x = 0;
	params->map_y = 0;
	params->init = 1;
	params->coin_collected = 0;
	params->old_x_player = 0;
	params->old_y_player = 0;
	params->count_movement = 0;
	params->is_jumping = 0;
	params->next_frame = 0;
	params->player_direction = 0;
	return (params);
}

