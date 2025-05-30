/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:50:59 by mleschev          #+#    #+#             */
/*   Updated: 2025/05/30 01:51:53 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# ifndef SPRITE_SIZE
#  define SPRITE_SIZE	32
# endif

typedef struct t_mlx_window
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
}	t_mlx_window;

// check_map.c
void		*get_map_params(t_mlx_window *params);
void		check_map_wall(t_mlx_window *params);
void		*check_line(t_mlx_window *params);
void		*fill_param(char c, t_mlx_window *params, int x, int y);
void		check_flood_fill(t_mlx_window *params, t_mlx_window *map);

//parse.c
void		malloc_array(t_mlx_window *map);
void		fill_map(t_mlx_window *map);
void		is_map_playable(t_mlx_window *map);
void		flood_fill(t_mlx_window *params, int x, int y);
void		fill_value_in_map(t_mlx_window *map);

// main.c
int			next_frame(t_mlx_window *params);
void		init_params_1(t_mlx_window *params);
void		init_params_2(t_mlx_window *params);
void		if_ext_ok(t_mlx_window *params);

// utils.c
void		refresh_character(t_mlx_window *params);
int			free_mlx(t_mlx_window *params);
void		refresh_map(t_mlx_window *params);
void		check_position_player(t_mlx_window *params);
void		free_array(t_mlx_window *params);

// listen.c
void		setup_hook(t_mlx_window *params);
int			handle_key(int keycode, t_mlx_window *params);
int			resize_window(int new_size_y, int new_size_x, t_mlx_window *params);
void		jumping(t_mlx_window *player);

// error.c
void		check_map_error(t_mlx_window *params);
void		print_error(char *error, t_mlx_window *params);
void		kill_process(t_mlx_window *map);
void		copy_value_for_check(t_mlx_window *map, t_mlx_window *cpy);

// put_texture.c
void		init_window(t_mlx_window *window);
void		init_graphic(t_mlx_window *window);
void		init_map_graphic(t_mlx_window *window);
void		refresh(t_mlx_window *window);
void		loop_init_map(t_mlx_window *window, int x, int y);

#endif
