/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:31:45 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/06 18:01:23 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int	check_wall(t_minilibx *mlx, double px, double py)
{
	double new_pos_x = px;
	double new_pos_y = py;
	int	x;
	int	y;

    if (mlx->key.move_forward)
    {
        new_pos_x += P_SPEED * cos(mlx->player.angle);
        new_pos_y += sin(mlx->player.angle) * P_SPEED;
    }
    else if (mlx->key.move_backward)
    {
        new_pos_x -= P_SPEED * cos(mlx->player.angle);
        new_pos_y -= sin(mlx->player.angle) * P_SPEED;
    }
    if (mlx->key.move_left)
    {
        new_pos_x -= P_SPEED * sin(mlx->player.angle);
        new_pos_y += P_SPEED * cos(mlx->player.angle);
    }
    else if (mlx->key.move_right)
    {
        new_pos_x += P_SPEED * sin(mlx->player.angle);
        new_pos_y -= P_SPEED * cos(mlx->player.angle);
    }

	x = floor(new_pos_x / TILE_SIZE);
	y = floor(new_pos_y / TILE_SIZE);

	if (mlx->data->map[y][x] == '1')
		return (0);
	return (1);
}

void events(t_minilibx *mlx)
{
	if (check_wall(mlx, mlx->player.px, mlx->player.py))
	{
    	if (mlx->key.move_forward)
    	{
    	    mlx->player.px += P_SPEED * cos(mlx->player.angle);
    	    mlx->player.py += P_SPEED * sin(mlx->player.angle);
    	}
    	else if (mlx->key.move_backward)
    	{
    	    mlx->player.px -= P_SPEED * cos(mlx->player.angle);
    	    mlx->player.py -= P_SPEED * sin(mlx->player.angle);
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


int	key_press(int keycode, void *cub3d)
{
	t_minilibx *mlx;

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
