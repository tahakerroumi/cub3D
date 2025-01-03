/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_intro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:30:02 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/01 03:24:19 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int	program_routine(void	*cub3d)
{
	t_minilibx	*mlx;

	mlx = (t_minilibx *)cub3d;
	events(mlx);
	draw_player(mlx);
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
	mlx_destroy_image(mlx->intro, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->intro,WIDTH, HEIGHT);
	return (0);
}

void	start_game(t_minilibx *mlx)
{
	mlx_hook(mlx->window, 2, (1L << 0), key_press, (void *)mlx);
	mlx_hook(mlx->window, 3, (1L << 1), key_release, (void *)mlx);
	mlx_loop_hook(mlx->intro, program_routine, (void *)mlx);
	mlx_loop(mlx->intro);
}

int	mlx_intro(t_minilibx *mlx, t_global *global)
{
	mlx->intro = mlx_init();
	if (!mlx->intro)
		return (1);
	mlx->window = mlx_new_window(mlx->intro, WIDTH, HEIGHT, "cub3d");
	mlx->img.img = mlx_new_image(mlx->intro, WIDTH, HEIGHT);
	if (!mlx->img.img)
		return (1);
	mlx->img.pixel_ptr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_HEIGHT, &mlx->img.endian);
	player_pos_dir(mlx, global);
	keys_init(mlx);
	return (0);
}
