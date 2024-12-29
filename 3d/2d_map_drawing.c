/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:29:42 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/29 16:29:06 by tkerroum         ###   ########.fr       */
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

void	draw_player(t_minilibx *mlx)
{
	int i;
	int j;

	i = -1;
	/*    drawing the player   */ 
	create_map(mlx, mlx->data);
	while (++i < TILE_SIZE / 5)
	{
		j = -1;
		while (++j < TILE_SIZE / 5)
				my_pixel_put(mlx->player.px + j, mlx->player.py + i, &mlx->img, 0x2986cc);
	}

	/*drawing the player pov*/ 

	mlx->ray.ray_angle = mlx->player.angle - (mlx->player.fov_rad / 2);
	i = 0;
	double	ver_distance;
	double	hor_distance;
	while (i < WIDTH)
	{
		hor_distance = get_horizontal(mlx, angle_check(mlx->ray.ray_angle));
		ver_distance = get_vertical(mlx, angle_check(mlx->ray.ray_angle));
		if (hor_distance < ver_distance)
			draw_ray(mlx,mlx->ray.ray_angle, hor_distance);
		else
			draw_ray(mlx,mlx->ray.ray_angle, ver_distance);
		i++;
		mlx->ray.ray_angle = angle_check(mlx->ray.ray_angle + (mlx->player.fov_rad / (WIDTH)));
	}
}
