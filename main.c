/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:47:37 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/12 16:34:48 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	mlx_window params;
	// map_params	map;
	
	// start parse-------------------------------------------
	if (argc > 2)
		print_error("Error\nToo much arguments !", NULL);
	else if (argc < 2)
		print_error("Error\nToo few arguments !", NULL);
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
	if (params->next_frame == 7000)
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
	if (params->is_jumping == 1)
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
	params->character_texture = NULL;
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
	return (params);
}

// delete --------------------------------------------------------------------------------
// int	main(int argc, char **argv) //check parse error
// {
// 	int x,y;
// 	x = 0;
// 	y = 0;
// 	if (argc == 1)
// 		ft_printf("va chier");
// 	mlx_window map;
	
// 	map.path = argv[1];
	
// 	get_map_params(&map);

// 	ft_printf("x : %d | Y : %d | error = %d\n\n", map.map_x, map.map_y, map.error);
// 	while (y < map.map_y)
// 	{
// 		x = 0;
// 		while (x < map.map_x)
// 		{
// 			ft_printf("%d ", map.array[y][x]);
// 			x++;
// 		}
// 		ft_printf("\n");
// 		y++;
// 	}
// }


