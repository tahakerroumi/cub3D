/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:29:42 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/15 07:47:41 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int	unit_circle(double angle, char c)
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

int	player_view_checker(float angle, double *inter, double *step,
		int is_horizon)
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

void	draw_wall(t_minilibx *mlx, int ray, int t_pix, int b_pix)
{
	int		y;
	int		py;
	t_img	*texture;

	y = t_pix;
	texture = get_wall_texture(mlx);
	while (t_pix < b_pix)
	{
		py = (t_pix - y) * ((double)mlx->ea_img->height / mlx->wall_height);
		my_pixel_put(ray, t_pix++, &mlx->img,
			get_color(get_x_cord(mlx), py, texture));
	}
}

void	draw_floor(t_minilibx *mlx, int ray, int b_pix)
{
	int	color;

	color = (mlx->data->floor_red << 16) | (mlx->data->floor_green << 8) | \
		mlx->data->floor_blue;
	while (b_pix < HEIGHT)
		my_pixel_put(ray, b_pix++, &mlx->img, color);
}

void	draw_ceiling(t_minilibx *mlx, int ray, int t_pix)
{
	int	i;
	int	color;

	color = (mlx->data->ceiling_red << 16) | (mlx->data->ceiling_green << 8) | \
		mlx->data->ceiling_blue;
	i = 0;
	while (i < t_pix)
		my_pixel_put(ray, i++, &mlx->img, color);
}
