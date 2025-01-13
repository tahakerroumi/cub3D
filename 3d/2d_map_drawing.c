/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:29:42 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/13 18:57:04 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int unit_circle(double angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int inter_check(float angle, double *inter, double *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

// void draw_wall(t_minilibx *mlx, int ray, int t_pix, int b_pix)
// {
//     mlx->ea_img = new_img(mlx, mlx->data->ea);  // Load the texture image

//     while (t_pix < b_pix)
//     {
//         // Calculate the texture coordinates for the current pixel
//         int tex_y = (int)((t_pix - (HEIGHT / 2 - (b_pix - t_pix) / 2)) * mlx->ea_img.height / (b_pix - t_pix));

//         // Get the color from the texture at the calculated coordinates
//         int color = mlx->ea_img.addr[tex_y * mlx->img.bits_per_pixel / 4 + tex_x];

//         // Draw the pixel on the screen
//         my_pixel_put(ray, t_pix++, &mlx->img, color);  // Use the correct image and color
//     }
// }

double	map( double max, double maxwh, double p)
{
	return (((p / maxwh) * max)  );
}

unsigned int	get_pixel_put(int x, int y, t_img *img)
{
	int	offset;

	if (x < 0 || y >= img->height || y < 0 || x >= img->width)
		return 0;
	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	if ( offset < 0)
		return 0;
    return   *(unsigned int *)(img->addr + offset);
}
float    get_xcord (t_minilibx *mlx)
{
	int x = 0;
//    if (mlx->ray.flag == 1)
//       return (fmodf(mlx->ray.wall_py * (64 / TILE_SIZE), 64));
//    return (fmodf(mlx->ray.wall_px  * (64 / TILE_SIZE), 64));
	if(mlx->ray.flag)
		x = (int)mlx->ray.wall_py % 64;
	else
		x = (int)mlx->ray.wall_px % 64;
	return x;
}

void draw_wall(t_minilibx *mlx, int ray, int t_pix, int b_pix)
{
	float x, y;
	int tot = b_pix - t_pix ;
	int i =0;
	x = get_xcord (mlx);//map(mlx->ea_img->width ,WIDTH, ray  );
	
	while (t_pix < b_pix)
	{
		y = map(mlx->ea_img->height , tot ,i++);
		my_pixel_put(ray, t_pix++, &mlx->img, get_pixel_put(x, y, mlx->ea_img));
		// mlx_put_image_to_window(mlx->intro, mlx->window, mlx->ea_img->img, 0, 0);
	}
}

void	draw_floor(t_minilibx *mlx, int ray, int b_pix)
{
	int color;

	color = (mlx->data->floor_red << 16) | (mlx->data->floor_green << 8) | mlx->data->floor_blue;
	while (b_pix < HEIGHT)
		my_pixel_put(ray, b_pix++, &mlx->img, color);
}

void	draw_ceiling(t_minilibx *mlx, int ray, int t_pix)
{
	int i;
	int	color;

	color = (mlx->data->ceiling_red << 16) | (mlx->data->ceiling_green << 8) | mlx->data->ceiling_blue;
	i = 0;
	while (i < t_pix)
		my_pixel_put(ray, i++, &mlx->img, color);
}

void	draw_walls(t_minilibx *mlx, int ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	mlx->ray.distance *= cos(angle_check(mlx->ray.ray_angle - mlx->player.angle));
	wall_h = (TILE_SIZE / mlx->ray.distance) * ((WIDTH / 2) / tan(mlx->player.fov_rad / 2));
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);

	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(mlx, ray, t_pix, b_pix);
	draw_floor(mlx, ray, b_pix);
	draw_ceiling(mlx, ray, t_pix);
}

void	rays_casting(t_minilibx *mlx)
{
	int i;

	mlx->ray.ray_angle = angle_check(mlx->player.angle - (mlx->player.fov_rad / 2));
	i = 0;
	double	ver_distance;
	double	hor_distance;
	
	while (i < WIDTH)
	{
		hor_distance = get_horizontal(mlx, (mlx->ray.ray_angle));
		ver_distance = get_vertical(mlx, (mlx->ray.ray_angle));
		if (hor_distance < ver_distance)
		{
			mlx->ray.distance = hor_distance;
			get_horizontal(mlx, (mlx->ray.ray_angle));
			mlx->ray.flag = 0;
		}
		else
		{
			mlx->ray.distance = ver_distance;
			get_vertical(mlx, (mlx->ray.ray_angle));
			mlx->ray.flag = 1;
		}
		draw_walls(mlx, i);
		i++;
		mlx->ray.ray_angle = angle_check(mlx->ray.ray_angle + (mlx->player.fov_rad / (WIDTH)));
	}
}
