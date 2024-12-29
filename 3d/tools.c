/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:48:22 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/29 17:06:39 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void player_pos_dir(t_minilibx *mlx, t_global *data)
{
	int i;
	int j;

	i = -1;
	while(data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'E')
			{
				mlx->data->map_x = j;
				mlx->data->map_y = i;
				player_type(&mlx->player, data->map[i][j]);
				mlx->player.px = j * TILE_SIZE + (TILE_SIZE / 2);
				mlx->player.py = i * TILE_SIZE + (TILE_SIZE / 2);
				mlx->player.fov_rad = FOV * (M_PI / 180);
			}
		}
	}
}

double	angle_check(double	ray)
{
	if (ray > 2 * M_PI)
		ray -= 2 * M_PI;
	else if (ray < 0)
		ray += 2 * M_PI;
	return (ray);	
}

void	player_type(t_player *player, char c)
{
	if (c == 'N')
		player->angle = (3 * M_PI) / 2;
	else if (c == 'S')
		player->angle = M_PI / 2;
	else if (c == 'W')
		player->angle = M_PI;
	else if (c == 'E')
		player->angle = 0.0;
	return ;
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->pixel_ptr + offset) = color;
}

// void draw_ray(t_minilibx *mlx, double ray_angle, double distance)
// {
//     int x_start = mlx->player.px; // Player's x-coordinate
//     int y_start = mlx->player.py; // Player's y-coordinate
//     int x_end = x_start + (int)(distance * cos(ray_angle)); // Endpoint based on distance
//     int y_end = y_start + (int)(distance * sin(ray_angle)); // Endpoint based on distance

//     int delta_x = abs(x_end - x_start);
//     int delta_y = abs(y_end - y_start);
//     int sign_x = x_start < x_end ? 1 : -1;
//     int sign_y = y_start < y_end ? 1 : -1;
//     int error = delta_x - delta_y;

//     double current_distance = 0;
//     while ((x_start != x_end || y_start != y_end) && current_distance <= distance)
//     {
//         // Check if the pixel is within screen bounds
//         if (x_start >= 0 && x_start < TILE_SIZE * mlx->data->map_width && y_start >= 0 && y_start < TILE_SIZE * mlx->data->map_height)
//         {
//             // Use your my_pixel_put function to set the pixel
//             my_pixel_put(x_start, y_start, &mlx->img, 0xFFFFFF); // White color
//         }

//         int error2 = error * 2;

//         if (error2 > -delta_y)
//         {
//             error -= delta_y;
//             x_start += sign_x;
//         }
//         if (error2 < delta_x)
//         {
//             error += delta_x;
//             y_start += sign_y;
//         }
//         current_distance = hypot(x_start - mlx->player.px, y_start - mlx->player.py);
//     }
// }


void draw_ray(t_minilibx *mlx, double ray_angle, double distance)
{
    int x_start = mlx->player.px;
    int y_start = mlx->player.py;

	int i = 0;
    while (i <= distance)
    {
		my_pixel_put(x_start + (i * cos(ray_angle)),  y_start + (i * sin(ray_angle)), &mlx->img, 0xFFFFFF);
		i++;
    }
}
