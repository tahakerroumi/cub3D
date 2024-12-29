/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:40:33 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/29 17:00:09 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

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
	if (data->map[i][j] == '0')
		draw_tile(i, j, &mlx->img, 0xf3bcc4);
	else if (data->map[i][j] == '1')
		draw_tile(i, j, &mlx->img, 0x4c1130);
	else if (data->map[i][j] == ' ')
		draw_tile(i, j, &mlx->img, 0x000000);
	else
		draw_tile(i, j, &mlx->img, 0xf3bcc4);
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