/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:47:17 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/01 04:12:03 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int	wall_hit(t_minilibx *mlx, double dx, double dy)
{
	int x;
	int y;
	if (dx < 0 || dy < 0 || dy >= mlx->data->map_height * TILE_SIZE || dx >= mlx->data->map_width * TILE_SIZE)
		return (0);
	x = floor(dx / TILE_SIZE);
	y = floor(dy / TILE_SIZE);
	if (x < 0 || y < 0 || y >= mlx->data->map_height || x >= mlx->data->map_width)
        return (0);
	if (mlx->data->map[y][x] == '1')
		return (0);
	return (1);
}

double	get_vertical(t_minilibx *mlx, double ray)
{
	double	dx;
	double	dy;
	double	nearest_x;
	double	nearest_y;
	int		pixel;

	dx = TILE_SIZE;
	dy = TILE_SIZE * tan(ray);
	nearest_x = floor(mlx->player.px / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(ray, &nearest_x, &dx, 0);
	nearest_y = mlx->player.py + (nearest_x - mlx->player.px) * tan(ray);
	if ((unit_circle(ray, 'x') && dy < 0) || (!unit_circle(ray, 'x') && dy > 0))
		dy *= -1;
	while (wall_hit(mlx, nearest_x - pixel, nearest_y))
	{
		nearest_x += dx;
		nearest_y += dy;
	}
	return (sqrt(pow(nearest_x - mlx->player.px, 2) + pow(nearest_y - mlx->player.py, 2)));
}

double	get_horizontal(t_minilibx *mlx, double ray)
{
	double		dx;
	double		dy;
	double		nearest_x;
	double		nearest_y;
	int			pixel;

	dy = TILE_SIZE;
	dx = TILE_SIZE / tan(ray);
	nearest_y = floor(mlx->player.py / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(ray, &nearest_y, &dy, 1);
	nearest_x = mlx->player.px + (nearest_y - mlx->player.py) / tan(ray);
	if ((unit_circle(ray, 'y') && dx > 0) || (!unit_circle(ray, 'y') && dx < 0))
		dx *= -1;
	while (wall_hit(mlx, nearest_x, nearest_y - pixel))
	{
		nearest_x += dx;
		nearest_y += dy;
	}
	return (sqrt(pow(nearest_x - mlx->player.px, 2) + pow(nearest_y - mlx->player.py, 2)));
}
