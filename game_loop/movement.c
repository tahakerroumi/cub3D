/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:00:09 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 18:08:38 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_direction(t_minilibx *mlx, double *dx, double *dy)
{
	*dx = 0;
	*dy = 0;
	if (mlx->key.move_forward)
	{
		*dx = cos(mlx->player.angle);
		*dy = sin(mlx->player.angle);
	}
	else if (mlx->key.move_backward)
	{
		*dx = -cos(mlx->player.angle);
		*dy = -sin(mlx->player.angle);
	}
	if (mlx->key.move_left)
	{
		*dx = -sin(mlx->player.angle);
		*dy = cos(mlx->player.angle);
	}
	else if (mlx->key.move_right)
	{
		*dx = sin(mlx->player.angle);
		*dy = -cos(mlx->player.angle);
	}
}

int	check_wall(t_minilibx *mlx, double px, double py)
{
	double	dx;
	double	dy;

	get_direction(mlx, &dx, &dy);
	px = floor((px + (dx * (P_SPEED + 10.0))) / TILE_SIZE);
	py = floor((py + (dy * (P_SPEED + 10.0))) / TILE_SIZE);
	return (safe_place(mlx->data->real_map, px, py));
}
