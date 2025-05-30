/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:47:37 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/30 01:52:27 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_window	params;

	if (argc > 2)
		print_error("Too much arguments!", NULL);
	else if (argc < 2)
		print_error("Too few arguments!", NULL);
	init_params_1(&params);
	params.path = argv[1];
	get_map_params(&params);
	init_window(&params);
	mlx_loop_hook(params.mlx, next_frame, &params);
	mlx_loop(params.mlx);
}

int	next_frame(t_mlx_window *params)
{
	params->next_frame += 1;
	if (params->array[params->y_player / SPRITE_SIZE]
		[params->x_player / SPRITE_SIZE] != 1)
	{
		params->old_x_player = params->x_player;
		params->old_y_player = params->y_player;
	}
	if (params->array[params->y_player / SPRITE_SIZE]
		[params->x_player / SPRITE_SIZE] == 4
		&& (params->c_nbr == params->coin_collected))
		free_mlx(params);
	if (params->next_frame == 20000)
	{
		params->next_frame = 0;
		if (params->array[params->y_player / SPRITE_SIZE + 1]
			[params->x_player / SPRITE_SIZE] != 1)
		{
			params->is_jumping = 1;
			params->y_player += SPRITE_SIZE;
		}
		else
			params->is_jumping = 0;
	}
	refresh_character(params);
	return (0);
}

void	init_params_1(t_mlx_window *params)
{
	params->mlx = NULL;
	params->window = NULL;
	params->wall_texture = NULL;
	params->coin_texture = NULL;
	params->coin_texture_2 = NULL;
	params->coin_texture_3 = NULL;
	params->exit_texture = NULL;
	params->exit_open_texture = NULL;
	params->background_texture = NULL;
	params->character_fall_texture_left = NULL;
	params->character_fall_texture_right = NULL;
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
	init_params_2(params);
}

void	init_params_2(t_mlx_window *params)
{
	params->x_exit = 0;
	params->y_exit = 0;
	params->coin_collected = 0;
	params->old_x_player = 0;
	params->old_y_player = 0;
	params->count_movement = 0;
	params->is_jumping = 0;
	params->next_frame = 0;
	params->player_direction = 0;
	params->fd = 0;
	params->map_x = 0;
	params->map_y = 0;
	params->init = 1;
}

void	if_ext_ok(t_mlx_window *params)
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
