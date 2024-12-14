/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:29:42 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/14 18:36:39 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/headerfile.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

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
		draw_tile(i, j, &mlx->img, 0xFF0000);
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
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
}
void draw_player(t_minilibx *mlx, t_global *data)
{
	int i = 0;
	int j;
	int c;
	int b = -1;
	while(data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
			{
				mlx->player.px = j;
				mlx->player.py = i;
				while (++b < TILE_SIZE / 3)
				{
					c = -1;
					while(++c < TILE_SIZE / 3)
						mlx_pixel_put(mlx->intro, mlx->window, mlx->player.px * TILE_SIZE + c, mlx->player.py * TILE_SIZE + b, 0xFFFFFF);
				}
			}
			j++;
		}
		i++;
	}
}