/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:50:59 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/23 04:56:24 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# ifndef TEXTURE_SIZE
# define TEXTURE_SIZE 32
# endif

typedef struct mlx_window
{
	void	*mlx;
	void	*window;
	void	*wall_texture;
	void	*coin_texture;
	void	*coin_texture_2;
	void	*coin_texture_3;
	void	*exit_texture;
	void	*exit_open_texture;
	void	*background_texture;
	void	*character_texture_right;
	void	*character_texture_left;
	void	*character_fall_texture_left;
	void	*character_fall_texture_right;
	int		x_player;
	int		y_player;
	int		player_direction;
	int		old_x_player;
	int		old_y_player;
	int		x_window;
	int		y_window;
	int		x_exit;
	int		y_exit;
	int		count_movement;
	int		map_x;
	int		map_y;
	int		p_nbr;
	int		c_nbr;
	int		e_nbr;
	char	*buf;
	int		error;
	int		init;
	int		fd;
	char	*path;
	int		**array;
	int		coin_collected;
	int		is_jumping;
	int		next_frame;
} mlx_window;

// check_map.c
void		*get_map_params(mlx_window *params);
void		check_map_wall(mlx_window *params);
void		if_ext_ok(mlx_window *params);
void		*check_line(mlx_window *params);
void		*fill_param(char c, mlx_window *params);

//parse.c
void		malloc_array(mlx_window *map);
void		fill_map(mlx_window *map);

// main.c
int			next_frame(mlx_window *params);
void		*init_map(mlx_window *params);

// utils.c
void		refresh_character(mlx_window *params);
int			free_mlx(mlx_window *params);
void		refresh_map(mlx_window *params);
void		check_position_player(mlx_window *params);
void		free_array(mlx_window *params);


// listen.c
void		setup_hook(mlx_window *params);
int			handle_key(int keycode, mlx_window *params);
int			resize_window(int new_size_y, int new_size_x, mlx_window *params);
void		jumping(mlx_window *player);

// error.c
void		check_map_error(mlx_window *params);
void		print_error(char *error, mlx_window *params);
void		kill_process(mlx_window *map);

// put_texture.c
void		init_window(mlx_window *window);
void		init_graphic(mlx_window *window);
void		init_map_graphic(mlx_window *window);
void		refresh(mlx_window *window);
void	loop_init_map(mlx_window *window, int x, int y);

# endif
