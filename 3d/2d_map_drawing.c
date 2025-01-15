/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:29:42 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/15 04:20:38 by tkerroum         ###   ########.fr       */
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

unsigned int 	get_color(int x, int y, t_img *text)
{
	char	*pixel;

	if (x < 0 || x >= text->width || y < 0 || y >= text->height)
		return (0);
	pixel = text->addr + (y * text->line_length + x
		* (text->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

int	get_x_cord(t_minilibx *mlx)
{
	if (mlx->ray.flag)
		return ((int)mlx->ray.wall_py % TILE_SIZE);
	else
		return ((int)mlx->ray.wall_px % TILE_SIZE);
}

void draw_wall(t_minilibx *mlx, int ray, int t_pix, int b_pix)
{
	int wall_height = b_pix - t_pix;
	int px = get_x_cord(mlx);
	
	int y = t_pix;
	while (t_pix < b_pix)
	{
		int py = (t_pix - y) * ((double)mlx->ea_img->height / wall_height);
		if (mlx->ray.flag == 1)
		{
			 if (mlx->ray.ray_angle < ((3 * M_PI) / 2) && mlx->ray.ray_angle > M_PI / 2)
				my_pixel_put(ray, t_pix++, &mlx->img, get_color(px, py, mlx->we_img));
			else
				my_pixel_put(ray, t_pix++, &mlx->img, get_color(px, py, mlx->ea_img));
		}
		else
		{
			if (mlx->ray.ray_angle < M_PI && mlx->ray.ray_angle > 0)
				my_pixel_put(ray, t_pix++, &mlx->img, get_color(px, py, mlx->no_img));
			else
				my_pixel_put(ray, t_pix++, &mlx->img, get_color(px, py, mlx->so_img));
		}
	}
}

void	draw_floor(t_minilibx *mlx, int ray, int b_pix)
{
	int color;

	color = (mlx->data->floor_red << 16) | (mlx->data->floor_green << 8) | mlx->data->floor_blue;
	while (b_pix < HEIGHT)
		my_pixel_put(ray, b_pix++, &mlx->img, color);
}

void	draw_ceiling(t_minilibx *mlx, int ray, int t_pix)
{
	int i;
	int	color;

	color = (mlx->data->ceiling_red << 16) | (mlx->data->ceiling_green << 8) | mlx->data->ceiling_blue;
	i = 0;
	while (i < t_pix)
		my_pixel_put(ray, i++, &mlx->img, color);
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
	draw_ceiling(mlx, ray, t_pix);
	draw_wall(mlx, ray, t_pix, b_pix);
	draw_floor(mlx, ray, b_pix);
}

void	 rays_casting(t_minilibx *mlx)
{
	int i;

	mlx->ray.ray_angle = angle_check(mlx->player.angle - (mlx->player.fov_rad / 2));
	i = 0;
	while (i < WIDTH)
	{
		if (get_horizontal(mlx, (mlx->ray.ray_angle)) < get_vertical(mlx, (mlx->ray.ray_angle)))
		{
			mlx->ray.distance = get_horizontal(mlx, (mlx->ray.ray_angle));
			mlx->ray.flag = 0;
		}
		else
		{
			mlx->ray.distance = get_vertical(mlx, (mlx->ray.ray_angle));
			mlx->ray.flag = 1;
		}
		draw_walls(mlx, i);
		i++;
		mlx->ray.ray_angle = angle_check(mlx->ray.ray_angle + (mlx->player.fov_rad / (WIDTH)));
	}
}
