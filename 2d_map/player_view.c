/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:02:18 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/19 02:01:19 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/headerfile.h"

void    draw_player_view(t_minilibx *mlx)
{
    int eye_x;
    int eye_y;
    int i = 0;

    if (mlx->player.angle < 0)
        mlx->player.angle += 2 * M_PI;
    else if (mlx->player.angle >= 2 * M_PI)
        mlx->player.angle -= 2 * M_PI;
    while (i < RADIUS)
    {
        eye_x = mlx->player.px + (i * cos(mlx->player.angle));
        eye_y = mlx->player.py + (i * sin(mlx->player.angle));
        
        my_pixel_put(eye_x, eye_y, &mlx->img, 0xC41E3A);
        i++;
    }
}
