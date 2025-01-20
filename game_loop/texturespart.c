/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturespart.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:05:52 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/20 11:55:09 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	*new_img(t_minilibx *data, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		error_print("Error\nMalloc failed\n");
	img->img = mlx_xpm_file_to_image(data->intro, path, &img->width,
			&img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

t_img	*get_wall_texture(t_minilibx *mlx)
{
	if (mlx->ray.flag == 1)
	{
		if (mlx->ray.ray_angle < ((3 * M_PI) / 2) && mlx->ray.ray_angle > M_PI
			/ 2)
			return (mlx->ea_img);
		return (mlx->we_img);
	}
	if (mlx->ray.ray_angle < M_PI && mlx->ray.ray_angle > 0)
		return (mlx->no_img);
	return (mlx->so_img);
}

unsigned int	get_color(int x, int y, t_img *text)
{
	char	*pixel;

	if (x < 0 || x >= text->width || y < 0 || y >= text->height)
		return (0);
	pixel = text->addr + (y * text->line_length + x * (text->bits_per_pixel
				/ 8));
	return (*(unsigned int *)pixel);
}

int	get_x_cord(t_minilibx *mlx)
{
	if (mlx->ray.flag)
		return ((int)mlx->ray.wall_py % TILE_SIZE);
	else
		return ((int)mlx->ray.wall_px % TILE_SIZE);
}
