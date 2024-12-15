/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_intro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:30:02 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/15 06:14:39 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/headerfile.h"

bool	can_mouve(t_minilibx *mlx, int keycode)
{
	int	x;
	int	y ;

	x = (int)(mlx->player.px / TILE_SIZE);
	y = (int)(mlx->player.py / TILE_SIZE);
	if (keycode == W)
		y = (int)((mlx->player.py - 10) / TILE_SIZE);
	else if (keycode == S)
		y = (int)((mlx->player.py + 20) / TILE_SIZE);
	else if (keycode == A)
		x = (int)((mlx->player.px - 10) / TILE_SIZE);
	else if (keycode == D)
		x = (int)((mlx->player.px + 20) / TILE_SIZE);
	if (x < 0 || y < 0 || y >= mlx->data->map_lenght * TILE_SIZE || x >= mlx->data->map_width * TILE_SIZE)
        return (false);
	return (mlx->data->map[y][x] == '0' || mlx->data->map[y][x] == 'N');
}

int key_routine(int keycode, t_minilibx *mlx)
{
	if (can_mouve(mlx, keycode))
	{
		if (keycode == W)
			mlx->player.py -= 10;
		else if (keycode == S)
			mlx->player.py += 10;
		else if (keycode == A)
			mlx->player.px -= 10;
		else if (keycode == D)
			mlx->player.px += 10;
	}
    create_map(mlx, mlx->data);
    draw_player(mlx);
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
    return (0);
}

void	start_game(t_minilibx *mlx, t_global *data)
{
	create_map(mlx, data);
	player_finder(mlx, data);
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
	mlx_hook(mlx->window, 02, (1L<<0), key_routine, mlx);
}

int	mlx_intro(t_minilibx *mlx, t_global *global)
{
	mlx->intro = mlx_init();
	if (!mlx->intro)
		return (1);
	mlx->window = mlx_new_window(mlx->intro, TILE_SIZE * global->map_width, TILE_SIZE * global->map_lenght, "cub3d");
	mlx->img.img = mlx_new_image(mlx->intro, TILE_SIZE * global->map_width, TILE_SIZE * global->map_lenght);
	if (!mlx->img.img)
		return (1);
	mlx->img.pixel_ptr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_lenght, &mlx->img.endian);
	return (0);
}