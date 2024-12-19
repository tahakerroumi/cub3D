/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_intro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:30:02 by tkerroum          #+#    #+#             */
/*   Updated: 2024/12/19 04:47:55 by tkerroum         ###   ########.fr       */
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

void player_finder(t_minilibx *mlx, t_global *data)
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
				|| data->map[i][j] == 'E') // must add the player definer
			{
				player_type(&mlx->player, data->map[i][j]);
				mlx->player.px = j * TILE_SIZE;
				mlx->player.py = i * TILE_SIZE;
				draw_player(mlx);
			}
		}
	}
}

int key_routine(int keycode, t_minilibx *mlx)
{
	if (keycode == W)
	{
		mlx->player.px += P_SPEED * cos(mlx->player.angle);
		mlx->player.py += sin(mlx->player.angle) * P_SPEED;
	}
	else if (keycode == S)
	{
		mlx->player.px -= P_SPEED * cos(mlx->player.angle);
		mlx->player.py -= sin(mlx->player.angle) * P_SPEED;
	}
	else if (keycode == D)
		mlx->player.px += 4;
	else if (keycode == A)
		mlx->player.px -= 4;
	else if (keycode == RIGHT)
		mlx->player.angle += 0.1;
	else if (keycode == LEFT)
		mlx->player.angle -= 0.1;
    create_map(mlx, mlx->data);
    draw_player(mlx);
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
    return (0);
}

void	start_game(t_minilibx *mlx, t_global *data)
{
	create_map(mlx, data);
	player_finder(mlx, data);
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
	mlx_hook(mlx->window, 02, (1L<<0), key_routine, mlx);
}

int	mlx_intro(t_minilibx *mlx, t_global *global)
{
	mlx->intro = mlx_init();
	if (!mlx->intro)
		return (1);
	mlx->window = mlx_new_window(mlx->intro, 1080, 650, "cub3d");
	mlx->img.img = mlx_new_image(mlx->intro, TILE_SIZE * global->map_width, TILE_SIZE * global->map_lenght);
	if (!mlx->img.img)
		return (1);
	mlx->img.pixel_ptr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_lenght, &mlx->img.endian);
	return (0);
}