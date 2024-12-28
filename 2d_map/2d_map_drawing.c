/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:29:42 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/28 18:12:01 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/headerfile.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	draw_tile(int i, int j, t_img *img, int color)
{
	int x;
	int y;

	y = -1;
	while (++y < TILE_SIZE)
	{
		x = -1;
		while (++x < TILE_SIZE)
			my_pixel_put(x + (j * TILE_SIZE), y + (i * TILE_SIZE), img, color);
	}	
}

void	pixel_manager(t_minilibx *mlx, t_global *data, int i, int j)
{
	if (data->map[i][j] == '0')
		draw_tile(i, j, &mlx->img, 0xf3bcc4);
	else if (data->map[i][j] == '1')
		draw_tile(i, j, &mlx->img, 0x4c1130);
	else if (data->map[i][j] == ' ')
		draw_tile(i, j, &mlx->img, 0x000000);
	else
		draw_tile(i, j, &mlx->img, 0xf3bcc4);
}

void	create_map(t_minilibx *mlx, t_global *data)
{
	int	x;
	int y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
			pixel_manager(mlx, data, y, x);
	}
}

int	wall_hit(t_minilibx *mlx, double dx, double dy)
{
	int x;
	int y;

	x = floor(dx / TILE_SIZE);
	y = floor(dy / TILE_SIZE);
	if (x < 0 || y < 0 || x >= mlx->data->map_height || y >= mlx->data->map_width)
        return (0); 
	if (mlx->data->map[y][x] == '1')
		return (0);
	return (1);
}

double	get_vertical(t_minilibx *mlx, double ray)
{
	double	dx;
	double	dy;
	double	nearest_x;
	double	nearest_y;

	dx = TILE_SIZE;
	dy = dx / tan(ray);
	nearest_x = TILE_SIZE - floor(mlx->player.px / TILE_SIZE) * TILE_SIZE;
	nearest_y = nearest_x * tan(ray);
	while (wall_hit(mlx, nearest_x, nearest_y))
	{
		nearest_x += dx;
		nearest_y += dy;
	}
	return (sqrt(pow(nearest_x - mlx->player.px, 2) + pow(nearest_y - mlx->player.py, 2)));
}

// double	get_horizontal(t_minilibx *mlx, double ray)
// {
// 	double	dx;
// 	double	dy;
// 	double	nearest_x;
// 	double	nearest_y;

// 	dy = TILE_SIZE;
// 	dx = dy / tan(ray);
// 	nearest_y = mlx->player.py - floor(mlx->player.py / TILE_SIZE) * TILE_SIZE;
// 	nearest_x = nearest_y / tan(ray);
// 	while (wall_hit(mlx, nearest_x, nearest_y))
// 	{
// 		nearest_x += dx;
// 		nearest_y += dy;
// 	}
// 	return (sqrt(pow(nearest_x - mlx->player.px, 2) + pow(nearest_y - mlx->player.py, 2)));
// }

double	get_horizontal(t_minilibx *mlx, double ray)
{
	double		dx;
	double		dy;
	double		nearest_x;
	double		nearest_y;
	// int			pixel;

	dy = TILE_SIZE;
	dx = TILE_SIZE / tan(ray);
	nearest_y = floor(mlx->player.py / TILE_SIZE) * TILE_SIZE;
	nearest_x = mlx->player.px + (nearest_y - mlx->player.py) / tan(ray);
	// pixel = inter_check(ray, &inter_y, &y_step, 1);
	// if ((unit_circle(ray, 'y') && x_step > 0) || (!unit_circle(ray, 'y') && x_step < 0))
	// 	x_step *= -1;
	while (wall_hit(mlx, nearest_x, nearest_y))
	{
		nearest_x += dx;
		nearest_y += dy;
	}
	return (sqrt(pow(nearest_x - mlx->player.px, 2) + pow(nearest_y - mlx->player.py, 2)));
}

void draw_ray(t_minilibx *mlx, double ray_angle, double distance)
{
    int x_start = mlx->player.px; // Player's x-coordinate
    int y_start = mlx->player.py; // Player's y-coordinate
    int x_end = x_start + (int)(distance * cos(ray_angle)); // Endpoint based on distance
    int y_end = y_start + (int)(distance * sin(ray_angle)); // Endpoint based on distance

    int delta_x = abs(x_end - x_start);
    int delta_y = abs(y_end - y_start);
    int sign_x = x_start < x_end ? 1 : -1;
    int sign_y = y_start < y_end ? 1 : -1;
    int error = delta_x - delta_y;

    double current_distance = 0;
    while ((x_start != x_end || y_start != y_end) && current_distance <= distance)
    {
        // Check if the pixel is within screen bounds
        if (x_start >= 0 && x_start < TILE_SIZE * mlx->data->map_width && y_start >= 0 && y_start < TILE_SIZE * mlx->data->map_height)
        {
            // Use your my_pixel_put function to set the pixel
            my_pixel_put(x_start, y_start, &mlx->img, 0xFFFFFF); // White color
        }

        int error2 = error * 2;

        if (error2 > -delta_y)
        {
            error -= delta_y;
            x_start += sign_x;
        }
        if (error2 < delta_x)
        {
            error += delta_x;
            y_start += sign_y;
        }

        // Calculate the current distance from the start point
        current_distance = hypot(x_start - mlx->player.px, y_start - mlx->player.py);
    }
}

void	draw_player(t_minilibx *mlx)
{
	int i;
	int j;

	i = -1;
	/*    drawing the player   */ 
	create_map(mlx, mlx->data);
	while (++i < TILE_SIZE / 5)
	{
		j = -1;
		while (++j < TILE_SIZE / 5)
				my_pixel_put(mlx->player.px + j, mlx->player.py + i, &mlx->img, 0x2986cc);
	}

	/*drawing the player pov*/ 

	mlx->ray.ray_angle = mlx->player.angle - (mlx->player.fov_rad / 2);
	i = 0;
	double	ver_distance;
	double	hor_distance;
	double	distance;
	while (i < TILE_SIZE * 20)
	{
		hor_distance = get_horizontal(mlx, angle_check(mlx->ray.ray_angle));
		ver_distance = get_vertical(mlx, angle_check(mlx->ray.ray_angle));
		if (hor_distance <= ver_distance)
			distance = hor_distance;
		else
			distance = ver_distance;
		// printf("vertical distance = -- > %d\n", (int)ver_distance);
		draw_ray(mlx,mlx->ray.ray_angle, distance);
		i++;
		mlx->ray.ray_angle = angle_check(mlx->ray.ray_angle + (mlx->player.fov_rad / (TILE_SIZE * TILE_SIZE)));
	}
}
