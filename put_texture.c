/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:27:12 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/12 16:33:19 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(mlx_window *window)
{
	window->x_window = window->map_x * TEXTURE_SIZE;
	window->y_window = window->map_y * TEXTURE_SIZE;
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
	
	height = TEXTURE_SIZE;
	width = TEXTURE_SIZE;
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
			loop_init_map(window, x, y);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	loop_init_map(mlx_window *window, int x, int y)
{
	if (window->array[y][x] == 1)
				mlx_put_image_to_window(window->mlx, window->window, window->wall_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			else if (window->array[y][x] == 2)
			{
				window->x_player = x * TEXTURE_SIZE;
				window->y_player = y * TEXTURE_SIZE;
				mlx_put_image_to_window(window->mlx, window->window, window->background_texture, x *TEXTURE_SIZE, y * TEXTURE_SIZE);
				mlx_put_image_to_window(window->mlx, window->window, window->character_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			}
			else if (window->array[y][x] == 3)
				mlx_put_image_to_window(window->mlx, window->window, window->coin_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			else if (window->array[y][x] == 4)
			{
				window->x_exit = x;
				window->y_exit = y;
				mlx_put_image_to_window(window->mlx, window->window, window->exit_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			}
			else if (window->array[y][x] == 5)
				mlx_put_image_to_window(window->mlx, window->window, window->background_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

void	refresh(mlx_window *window)
{
	int	y;
	int	x;

	y = window->old_y_player / TEXTURE_SIZE;
	x = window->old_x_player / TEXTURE_SIZE;
	if (window->array[y][x] == 3)
	{
			window->array[y][x] = 5;
			window->coin_collected++;
		if (window->c_nbr == window->coin_collected)
			mlx_put_image_to_window(window->mlx, window->window, window->coin_texture, window->x_exit * TEXTURE_SIZE, window->y_exit * TEXTURE_SIZE);
	}
	else if (window->array[y][x] == 4)
	{
		mlx_put_image_to_window(window->mlx, window->window, window->exit_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	}
	else if (window->array[y][x] == 5 || window->array[y][x] == 2)
		mlx_put_image_to_window(window->mlx, window->window, window->background_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	else if (window->array[y][x] == 1)
		mlx_put_image_to_window(window->mlx, window->window, window->wall_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);	
}
