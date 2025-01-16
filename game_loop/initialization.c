/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:55:41 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/16 13:43:32 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void	keys_init(t_minilibx *mlx)
{
	mlx->key.move_backward = 0;
	mlx->key.move_forward = 0;
	mlx->key.move_left = 0;
	mlx->key.move_right = 0;
	mlx->key.rotate_left = 0;
	mlx->key.rotate_right = 0;
}

int	textures_init(t_minilibx *mlx)
{
	mlx->ea_img = new_img(mlx, mlx->data->ea);
	mlx->we_img = new_img(mlx, mlx->data->we);
	mlx->so_img = new_img(mlx, mlx->data->so);
	mlx->no_img = new_img(mlx, mlx->data->no);
	if (!mlx->ea_img || !mlx->we_img || !mlx->so_img || !mlx->no_img)
		return (1);
	return (0);
}

int	mlx_intro(t_minilibx *mlx, t_global *global)
{
	mlx->data = global;
	mlx->intro = mlx_init();
	if (!mlx->intro)
		return (1);
	mlx->window = mlx_new_window(mlx->intro, WIDTH, HEIGHT, "cub3d");
	mlx->img.img = mlx_new_image(mlx->intro, WIDTH, HEIGHT);
	if (!mlx->img.img)
		return (1);
	mlx->img.pixel_ptr = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bits_per_pixel, &mlx->img.line_height, &mlx->img.endian);
	player_pos_dir(mlx, global);
	keys_init(mlx);
	if (textures_init(mlx))
		return (1);
	return (0);
}
