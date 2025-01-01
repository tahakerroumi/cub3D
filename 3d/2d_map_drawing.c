/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:29:42 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/01 03:21:19 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int unit_circle(double angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int inter_check(float angle, double *inter, double *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

void draw_wall(t_minilibx *mlx, int ray, int t_pix, int b_pix)
{
	while (t_pix < b_pix)
		my_pixel_put(ray, t_pix++, &mlx->img, 0xffd83b);
}

void	draw_walls(t_minilibx *mlx, int ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	mlx->ray.distance *= cos(angle_check(mlx->ray.ray_angle - mlx->player.angle));
	wall_h = (TILE_SIZE / mlx->ray.distance) * ((WIDTH / 2) / tan(mlx->player.fov_rad / 2));
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(mlx, ray, t_pix, b_pix);
}

void	draw_player(t_minilibx *mlx)
{
	int i;

	mlx->ray.ray_angle = angle_check(mlx->player.angle - (mlx->player.fov_rad / 2));
	i = 0;
	double	ver_distance;
	double	hor_distance;
	while (i < WIDTH)
	{
		hor_distance = get_horizontal(mlx, (mlx->ray.ray_angle));
		ver_distance = get_vertical(mlx, (mlx->ray.ray_angle));
		if (hor_distance < ver_distance)
			mlx->ray.distance = hor_distance;
		else
			mlx->ray.distance = ver_distance;
		draw_walls(mlx, i);
		i++;
		mlx->ray.ray_angle = angle_check(mlx->ray.ray_angle + (mlx->player.fov_rad / (WIDTH)));
	}
}
