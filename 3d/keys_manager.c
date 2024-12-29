/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:31:45 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/29 17:52:45 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void events(t_minilibx *mlx)
{
    if (mlx->key.move_forward)
    {
        mlx->player.px += P_SPEED * cos(mlx->player.angle);
        mlx->player.py += sin(mlx->player.angle) * P_SPEED;
    }
    else if (mlx->key.move_backward)
    {
        mlx->player.px -= P_SPEED * cos(mlx->player.angle);
        mlx->player.py -= sin(mlx->player.angle) * P_SPEED;
    }

    if (mlx->key.move_left)
    {
        mlx->player.px -= P_SPEED * sin(mlx->player.angle);
        mlx->player.py += P_SPEED * cos(mlx->player.angle);
    }
    else if (mlx->key.move_right)
    {
        mlx->player.px += P_SPEED * sin(mlx->player.angle);
        mlx->player.py -= P_SPEED * cos(mlx->player.angle);
    }
    if (mlx->key.rotate_left)
    {
        mlx->player.angle -= R_SPEED;
        if (mlx->player.angle < 0)
            mlx->player.angle += 2 * M_PI;
    }
    else if (mlx->key.rotate_right)
    {
        mlx->player.angle += R_SPEED;
        if (mlx->player.angle > 2 * M_PI)
            mlx->player.angle -= 2 * M_PI;
    }
}


int	key_press(int keycode, void *cub)
{
	t_minilibx *mlx;

	mlx = (t_minilibx *)cub;
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
	return (0);
}

int	key_release(int keycode, void *cub)
{
	t_minilibx *mlx;

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

void	keys_init(t_minilibx *mlx)
{
	mlx->key.move_backward = 0;
	mlx->key.move_forward = 0;
	mlx->key.move_left = 0;
	mlx->key.move_right = 0;
	mlx->key.rotate_left = 0;
	mlx->key.rotate_right = 0;
}
