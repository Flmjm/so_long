/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:27:12 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/05 17:24:12 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(mlx_window *window)
{
	window->x_window = window->map_x * 32;
	window->y_window = window->map_y * 32;
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, window->x_window, window->y_window, "So_long");
	if (!window->window)
		print_error("Error\nCan't open the window", NULL);
	init_graphic(window);
	init_map_graphic(window);
	setup_hook(window);
}

void	init_graphic(mlx_window *window)
{
	int	height;
	int width;
	
	height = 32;
	width = 32;
	window->wall_texture = mlx_xpm_file_to_image(window->mlx, "test/block.xpm", &width, &height);
	window->character_texture = mlx_xpm_file_to_image(window->mlx,"test/aled.xpm", &width, &height);
	window->coin_texture = mlx_xpm_file_to_image(window->mlx,"test/coin.xpm", &width, &height);
	window->exit_texture = mlx_xpm_file_to_image(window->mlx,"test/exit.xpm", &width, &height);
	window->background_texture = mlx_xpm_file_to_image(window->mlx, "test/mdr.xpm", &width, &height);
}

void	init_map_graphic(mlx_window *window)
{
	int	y;
	int	x;
	
	y = 0;
	while (window->array[y])
	{
		x = 0;
		while (window->array[y][x])
		{
			if (window->array[y][x] == 1)
				mlx_put_image_to_window(window->mlx, window->window, window->wall_texture, x * 32, y * 32);
			else if (window->array[y][x] == 2)
			{
				window->x_player = x * 32;
				window->y_player = y * 32;
				mlx_put_image_to_window(window->mlx, window->window, window->background_texture, x *32, y * 32);
				mlx_put_image_to_window(window->mlx, window->window, window->character_texture, x * 32, y * 32);
			}
			else if (window->array[y][x] == 3)
				mlx_put_image_to_window(window->mlx, window->window, window->coin_texture, x * 32, y * 32);
			else if (window->array[y][x] == 4)
				mlx_put_image_to_window(window->mlx, window->window, window->exit_texture, x * 32, y * 32);
			else if (window->array[y][x] == 5)
				mlx_put_image_to_window(window->mlx, window->window, window->background_texture, x * 32, y * 32);
			ft_printf(":%d[%d][%d]:", window->array[y][x], y, x);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	refresh(mlx_window *window)
{
	int	y;
	int	x;

	y = window->old_y_player / 32;
	x = window->old_x_player / 32;
	if (window->array[y][x] == 3)
	{
		mlx_put_image_to_window(window->mlx, window->window, window->background_texture, x * 32, y * 32);
		window->coin_collected++;
	}
	else if (window->array[y][x] == 4)
		mlx_put_image_to_window(window->mlx, window->window, window->exit_texture, x * 32, y * 32);
	else if (window->array[y][x] == 2)
		mlx_put_image_to_window(window->mlx, window->window, window->background_texture, x * 32, y * 32);
	else if (window->array[y][x] == 5)
		mlx_put_image_to_window(window->mlx, window->window, window->background_texture, x * 32, y * 32);
	else if (window->array[y][x] == 1)
		mlx_put_image_to_window(window->mlx, window->window, window->wall_texture, x * 32, y * 32);	
}
