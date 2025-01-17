/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:47:17 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/20 15:39:42 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	world_manager(t_minilibx *mlx, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	mlx->ray.distance *= cos(angle_check(mlx->ray.ray_angle
				- mlx->player.angle));
	wall_h = (TILE_SIZE / mlx->ray.distance) * ((WIDTH / 2)
			/ tan(mlx->player.fov_rad / 2));
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	mlx->wall_height = wall_h;
	draw_ceiling(mlx, ray, t_pix);
	draw_wall(mlx, ray, t_pix, b_pix);
	draw_floor(mlx, ray, b_pix);
}

int	wall_hit(t_minilibx *mlx, double dx, double dy)
{
	int	x;
	int	y;

	if (dx < 0 || dy < 0)
		return (0);
	x = (int)(dx / TILE_SIZE);
	y = (int)(dy / TILE_SIZE);
	if (x < 0 || y < 0 || y >= mlx->data->map_height
		|| x >= mlx->data->map_width)
		return (0);
	if (mlx->data->real_map[y] && x <= (int)ft_strlen(mlx->data->real_map[y]))
		if (mlx->data->real_map[y][x] != '1')
			return (1);
	return (0);
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
	pixel = player_view_checker(ray, &nearest_x, &dx, 0);
	nearest_y = mlx->player.py + (nearest_x - mlx->player.px) * tan(ray);
	if ((unit_circle(ray, 'x') && dy < 0) || (!unit_circle(ray, 'x') && dy > 0))
		dy *= -1;
	while (wall_hit(mlx, nearest_x - pixel, nearest_y))
	{
		nearest_x += dx;
		nearest_y += dy;
	}
	mlx->ray.wall_px = nearest_x;
	mlx->ray.wall_py = nearest_y;
	return (sqrt(pow(nearest_x - mlx->player.px, 2) + pow(nearest_y
				- mlx->player.py, 2)));
}

double	get_horizontal(t_minilibx *mlx, double ray)
{
	double	dx;
	double	dy;
	double	nearest_x;
	double	nearest_y;
	int		pixel;

	dy = TILE_SIZE;
	dx = TILE_SIZE / tan(ray);
	nearest_y = floor(mlx->player.py / TILE_SIZE) * TILE_SIZE;
	pixel = player_view_checker(ray, &nearest_y, &dy, 1);
	nearest_x = mlx->player.px + (nearest_y - mlx->player.py) / tan(ray);
	if ((unit_circle(ray, 'y') && dx > 0) || (!unit_circle(ray, 'y') && dx < 0))
		dx *= -1;
	while (wall_hit(mlx, nearest_x, nearest_y - pixel))
	{
		nearest_x += dx;
		nearest_y += dy;
	}
	mlx->ray.wall_px = nearest_x;
	mlx->ray.wall_py = nearest_y;
	return (sqrt(pow(nearest_x - mlx->player.px, 2) + pow(nearest_y
				- mlx->player.py, 2)));
}

void	ray_casting(t_minilibx *mlx)
{
	int	i;

	mlx->ray.ray_angle = angle_check(mlx->player.angle - (mlx->player.fov_rad
				/ 2));
	i = 0;
	while (i < WIDTH)
	{
		if (get_horizontal(mlx, (mlx->ray.ray_angle)) < get_vertical(mlx,
				(mlx->ray.ray_angle)))
		{
			mlx->ray.distance = get_horizontal(mlx, (mlx->ray.ray_angle));
			mlx->ray.flag = 0;
		}
		else
		{
			mlx->ray.distance = get_vertical(mlx, (mlx->ray.ray_angle));
			mlx->ray.flag = 1;
		}
		world_manager(mlx, i);
		i++;
		mlx->ray.ray_angle = angle_check(mlx->ray.ray_angle
				+ (mlx->player.fov_rad / (WIDTH)));
	}
}
