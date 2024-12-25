/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:29:42 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/25 12:58:04 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/headerfile.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0)
		return ;
	else if (x >= LENGHT)
		return ;
	if (y < 0)
		return ;
	else if (y >= WIDTH)
		return ;
	offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	draw_tile(int i, int j, t_img *img, int color)
{
	int x;
	int y;

	y = -1;
	while (++y < TILE_SIZE)
	{
		x = -1;
		while (++x < TILE_SIZE)
			my_pixel_put(x + (j * TILE_SIZE), y + (i * TILE_SIZE), img, color);
	}	
}

void	pixel_manager(t_minilibx *mlx, t_global *data, int i, int j)
{
	if (data->map[i][j] == '0' || data->map[i][j] == 'N')
		draw_tile(i, j, &mlx->img, 0xAAAAAA);
	else if (data->map[i][j] == '1')
		draw_tile(i, j, &mlx->img, 0xFF000000);
	else if (data->map[i][j] == ' ')
		draw_tile(i, j, &mlx->img, 0x000000);
	else
		draw_tile(i, j, &mlx->img, 0xAAAAAA);
}

void	create_map(t_minilibx *mlx, t_global *data)
{
	int	x;
	int y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
			pixel_manager(mlx, data, y, x);
	}
}

void	draw_player(t_minilibx *mlx)
{
	int i;
	int j;

	i = -1;
	while (++i < TILE_SIZE / 3)
	{
		j = -1;
		while (++j < TILE_SIZE / 3)
				my_pixel_put(mlx->player.px + j, mlx->player.py + i, &mlx->img, 0xFFFFFF);
	}
	draw_player_view(mlx);
}
