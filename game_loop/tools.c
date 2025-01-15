/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:48:22 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/15 04:51:03 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void	player_pos_dir(t_minilibx *mlx, t_global *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				player_type(&mlx->player, data->map[i][j]);
				mlx->player.px = j * TILE_SIZE + (TILE_SIZE / 2);
				mlx->player.py = i * TILE_SIZE + (TILE_SIZE / 2);
				mlx->player.fov_rad = FOV * (M_PI / 180);
			}
		}
	}
}

double	angle_check(double ray)
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

	if (x < 0 || y >= HEIGHT || y < 0 || x >= WIDTH)
		return ;
	offset = (y * img->line_height) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

int	safe_place(char **map, int x, int y)
{
	if (map[y][x] == '0')
		return (1);
	if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
		|| map[y][x] == 'E')
		return (1);
	return (0);
}