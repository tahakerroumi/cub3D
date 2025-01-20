/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:31:45 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/20 13:32:11 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_position(t_minilibx *mlx)
{
	double	dx;
	double	dy;

	dx = 0.0;
	dy = 0.0;
	get_direction(mlx, &dx, &dy);
	if (check_wall(mlx, mlx->player.px, mlx->player.py))
	{
		mlx->player.px += dx * P_SPEED;
		mlx->player.py += dy * P_SPEED;
	}
}

void	update_rotation(t_minilibx *mlx)
{
	if (mlx->key.rotate_left)
		mlx->player.angle = angle_check(mlx->player.angle - R_SPEED);
	else if (mlx->key.rotate_right)
		mlx->player.angle = angle_check(mlx->player.angle + R_SPEED);
}

void	events(t_minilibx *mlx)
{
	update_position(mlx);
	update_rotation(mlx);
}

int	key_press(int keycode, void *cub3d)
{
	t_minilibx	*mlx;

	mlx = (t_minilibx *)cub3d;
	if (keycode == W)
		mlx->key.move_forward = 1;
	else if (keycode == S)
		mlx->key.move_backward = 1;
	else if (keycode == D)
		mlx->key.move_left = 1;
	else if (keycode == A)
		mlx->key.move_right = 1;
	else if (keycode == LEFT)
		mlx->key.rotate_left = 1;
	else if (keycode == RIGHT)
		mlx->key.rotate_right = 1;
	else if (keycode == ESC)
		end_program(cub3d);
	return (0);
}

int	key_release(int keycode, void *cub)
{
	t_minilibx	*mlx;

	mlx = (t_minilibx *)cub;
	if (keycode == W)
		mlx->key.move_forward = 0;
	else if (keycode == S)
		mlx->key.move_backward = 0;
	else if (keycode == D)
		mlx->key.move_left = 0;
	else if (keycode == A)
		mlx->key.move_right = 0;
	else if (keycode == LEFT)
		mlx->key.rotate_left = 0;
	else if (keycode == RIGHT)
		mlx->key.rotate_right = 0;
	return (0);
}
