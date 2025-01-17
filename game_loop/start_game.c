/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:30:02 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 18:05:53 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	program_routine(void *cub3d)
{
	t_minilibx	*mlx;

	mlx = (t_minilibx *)cub3d;
	events(mlx);
	ray_casting(mlx);
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
	return (0);
}

int	end_program(void *cub3d)
{
	t_minilibx	*mlx;

	mlx = (t_minilibx *)cub3d;
	mlx_destroy_image(mlx->intro, mlx->img.img);
	mlx_destroy_window(mlx->intro, mlx->window);
	free_elements(mlx);
	exit(1);
}

void	start_game(t_minilibx *mlx)
{
	mlx_hook(mlx->window, 02, (1L << 0), key_press, (void *)mlx);
	mlx_hook(mlx->window, 03, (1L << 1), key_release, (void *)mlx);
	mlx_hook(mlx->window, 17, 0, end_program, (void *)mlx);
	mlx_loop_hook(mlx->intro, program_routine, (void *)mlx);
	mlx_loop(mlx->intro);
}
