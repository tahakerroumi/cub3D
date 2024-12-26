/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_intro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:30:02 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/26 20:06:22 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/headerfile.h"

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
				mlx->player.px = j * TILE_SIZE;
				mlx->player.py = i * TILE_SIZE;
				mlx->player.fov_rad = FOV * (M_PI / 180);
			}
		}
	}
}

// void draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
// {
//  int  i;
//  int  c;

// 	i = b_pix;
// 	while (i < S_H)
// 		my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF); // floor
// 	i = 0;
// 	while (i < t_pix)
// 		my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF); // ceiling
// }

// int get_color(t_mlx *mlx, int flag) // get the color of the wall
// {
// 	mlx->ray->ray_ngl = nor_angle(mlx->ray->ray_ngl); // normalize the angle
// 	if (flag == 0)
// 	{
// 		if (mlx->ray->ray_ngl > M_PI / 2 && mlx->ray->ray_ngl < 3 * (M_PI / 2))
// 			return (0xB5B5B5FF); // west wall
// 		else
// 			return (0xB5B5B5FF); // east wall
// 	}
// 	else
// 	{
// 		if (mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI)
// 			return (0xF5F5F5FF); // south wall
// 		else
// 			return (0xF5F5F5FF); // north wall
// 	}
// }

double	angle_check(double	ray)
{
	if (ray > 2 * M_PI)
		ray -= 2 * M_PI;
	else if (ray < 0)
		ray += 2 * M_PI;
	return (ray);	
}

void	draw_wall(t_minilibx *mlx, int ray, double t_pix, double b_pix)
{
	int		y;
	int		color;

	// Ensure values are within bounds
	if (ray < 0 || ray >= WIDTH || t_pix < 0 || b_pix >= LENGHT)
		return;

	// Define the wall color (e.g., white)
	color = 0xFFFFFF; // RGB hex value for white

	// Loop through each pixel in the column to draw the wall slice
	y = (int)t_pix;
	while (y < (b_pix))
	{
		// Safely calculate the address in the image buffer and set the pixel color
		// if (y >= 0 && y < LENGHT)
			*(unsigned int *)(mlx->img.pixel_ptr + (y * mlx->img.line_lenght + ray * (mlx->img.bits_per_pixel / 8))) = color;
		y++;
	}
}

void render_wall(t_minilibx *mlx, int ray)
{
    double wall_h;
    double b_pix;
    double t_pix;

    // Correct for fish-eye effect by adjusting the ray distance
    mlx->ray.distance *= cos(angle_check(mlx->ray.ray_angle - mlx->player.angle));
    
    // Calculate wall height based on distance and screen projection
    if (mlx->ray.distance > 0) // Prevent division by zero
        wall_h = (TILE_SIZE / mlx->ray.distance) * ((LENGHT / 2) / tan(mlx->player.fov_rad / 2));
    else
        wall_h = 0;

    // Determine top and bottom pixel positions for the wall slice
    b_pix = (LENGHT / 2) + (wall_h / 2);
    t_pix = (LENGHT / 2) - (wall_h / 2);

    // Clamp to screen bounds
    if (b_pix > LENGHT)
        b_pix = LENGHT;
    if (t_pix < 0)
        t_pix = 0;

    // Draw the wall slice
    draw_wall(mlx, ray, t_pix, b_pix);

    // Optionally draw the floor and ceiling
    // draw_floor_ceiling(mlx, ray, t_pix, b_pix);
}

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

int wall_hit(double x, double y, t_minilibx *mlx)
{
	int  x_m;
	int  y_m;

	if (x < 0 || y < 0 || y > mlx->data->map_width  * TILE_SIZE)
		return (0);
	x_m = floor(x / TILE_SIZE);
	y_m = floor(y / TILE_SIZE);
	if (y_m >= mlx->data->map_width || x_m >= (int)ft_strlen(mlx->data->map[y_m]))
		return (0);
	if (mlx->data->map[y_m] && x_m <= (int)ft_strlen(mlx->data->map[y_m]))
		if (mlx->data->map[y_m][x_m] == '1')
			return (0);
	return (1);
}

double	get_vertical(t_minilibx	*mlx, double ray)
{
	double		y_step;
	double		x_step;
	double		inter_x;
	double		inter_y;
	int			pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(ray);
	inter_x = floor(mlx->player.px / TILE_SIZE) * TILE_SIZE;
	inter_y = mlx->player.py + (inter_x - mlx->player.px) * tan(ray);
	pixel = inter_check(ray, &inter_x, &x_step, 0);
	if ((unit_circle(ray, 'x') && y_step < 0) || (!unit_circle(ray, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(inter_x - pixel, inter_y, mlx))
	{
		inter_x += x_step;
		inter_y += y_step;
	}
	return (sqrt(pow(inter_x - mlx->player.px, 2) + pow(inter_y - mlx->player.py, 2)));
}

double	get_horizontal(t_minilibx *mlx, double ray)
{
	double		y_step;
	double		x_step;
	double		inter_x;
	double		inter_y;
	int			pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(ray);
	inter_y = floor(mlx->player.py / TILE_SIZE) * TILE_SIZE;
	inter_x = mlx->player.px + (inter_y - mlx->player.py) / tan(ray);
	pixel = inter_check(ray, &inter_y, &y_step, 1);
	if ((unit_circle(ray, 'y') && x_step > 0) || (!unit_circle(ray, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(inter_x, inter_y - pixel, mlx))
	{
		inter_x += x_step;
		inter_y += y_step;
	}
	return (sqrt(pow(inter_x - mlx->player.px, 2) + pow(inter_y - mlx->player.py, 2)));
}

void	rays_loop(t_minilibx *mlx)
{
	int			ray;
	double		ver_point;
	double		hor_point;

	mlx->ray.ray_angle = mlx->player.angle - (mlx->player.fov_rad / 2);
	ray = 0;
	while (ray <  WIDTH - 1)
	{
		mlx->ray.flag = 0;
		hor_point = get_horizontal(mlx, angle_check(mlx->ray.ray_angle));
		ver_point = get_vertical(mlx, angle_check(mlx->player.angle));
		if (ver_point <= hor_point)
			mlx->ray.distance = ver_point;
		else
		{
			mlx->ray.distance = hor_point;
			mlx->ray.flag = 1;
		}
		render_wall(mlx, ray);
		ray++;
		mlx->ray.ray_angle = angle_check(mlx->ray.ray_angle + (mlx->player.fov_rad / LENGHT));
	}
}

int check_collision(double x, double y, t_minilibx *mlx)
{
    int map_x = (int)(x / TILE_SIZE);
    int map_y = (int)(y / TILE_SIZE);

    if (map_x >= 0 && map_x < mlx->data->map_width && map_y >= 0 && map_y < mlx->data->map_lenght)
        return (mlx->data->map[map_y][map_x] == '1');
    return (1);
}

void events(t_minilibx *mlx)
{
    if (mlx->key.move_forward)
    {
        mlx->player.px += cos(mlx->player.angle) * P_SPEED;
        mlx->player.py += sin(mlx->player.angle) * P_SPEED;
        if (check_collision(mlx->player.px, mlx->player.py, mlx))
        {
            mlx->player.px -= cos(mlx->player.angle) * P_SPEED;
            mlx->player.py -= sin(mlx->player.angle) * P_SPEED;
        }
    }
}

int	program_routine(void	*cub3d)
{
	t_minilibx	*mlx;

	mlx = (t_minilibx *)cub3d;
	events(mlx);
	rays_loop(mlx);
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
	// mlx_destroy_image(mlx->intro, mlx->img.img);
	return (0);
}

int	key_press(int keycode, void *cub)
{
	t_minilibx *mlx;

	mlx = (t_minilibx *)cub;
	if (keycode == W)
		mlx->key.move_forward = 1;
	return (0);
}

int	key_release(int keycode, void *cub)
{
	t_minilibx *mlx;

	mlx = (t_minilibx *)cub;
	if (keycode == W)
		mlx->key.move_forward = 0;
	return (0);
}

void	start_game(t_minilibx *mlx)
{
	mlx_hook(mlx->window, 2, (1L << 0), key_press, (void *)mlx);
	mlx_hook(mlx->window, 3, (1L << 1), key_release, (void *)mlx);
	mlx_loop_hook(mlx->intro, program_routine, (void *)mlx);
	mlx_loop(mlx->intro);
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

int	mlx_intro(t_minilibx *mlx, t_global *global)
{
	mlx->intro = mlx_init();
	if (!mlx->intro)
		return (1);
	mlx->window = mlx_new_window(mlx->intro, WIDTH, LENGHT, "cub3d");
	mlx->img.img = mlx_new_image(mlx->intro, WIDTH, LENGHT);
	if (!mlx->img.img)
		return (1);
	mlx->img.pixel_ptr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_lenght, &mlx->img.endian);
	player_pos_dir(mlx, global);
	keys_init(mlx);
	return (0);
}