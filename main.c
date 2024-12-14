/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:22 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/14 18:25:32 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/headerfile.h"

int	comparaison2(char *str)
{
	if (ft_strncmp(ft_strtrim(str), "NO", 2) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "SO", 2) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "WE", 2) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "EA", 2) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "F", 1) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "C", 1) == 0)
		return (-1);
	return (1);
}

char	**doubleptr_strim2(char **str, char **map, int end, int start)
{
	int	i;

	i = -1;
	while (start <= end)
	{
		map[i++] = ft_strdup(str[start]);
		start++;
	}
	map[i] = NULL;
	return (map);
}

char	**doubleptr_strim(char **str, int end)
{
	char	**map;
	int		i;
	int		size;
	int		start;

	i = 0;
	size = 0;
	start = 0;
	while (str[i++] && (comparaison2(str[i]) == -1
			|| ft_strncmp
			(ft_strtrim(str[i]), "\0", 2) == 0))
		size++;
	start = size;
	if (str[end] == NULL)
		end--;
	i = end;
	while (end > start && ft_strncmp(ft_strtrim(str[i--]), "\0", 2) == 0)
		end--;
	map = malloc((end - start + 2) * sizeof(char *));
	if (!map)
		return (NULL);
	return (doubleptr_strim2(str, map, end, start));
}

int	comparaison(char *str)
{
	if (ft_strncmp(ft_strtrim(str), "NO", 2) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "SO", 2) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "WE", 2) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "EA", 2) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "F", 1) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "C", 1) != 0)
		return (-1);
	return (1);
}

// void create_map(t_minilibx *mlx, t_global *data)
// {
//     int i, j;

//     i = 0;
//     while (data->map[i])
//     {
//         j = 0;
//         while (data->map[i][j])
//         {
//             int x_start = j * TILE_SIZE;
//             int y_start = i * TILE_SIZE;
//             int color;

//             if (data->map[i][j] == '1')
//                 color = 0xFF0000;
//             else if (data->map[i][j] == '0' || data->map[i][j] == 'N')
//                 color = 0xAAAAAA;
//             else if (data->map[i][j] == ' ')
//                 color = 0x000000;
//             else
//                 color = 0x000000;
//             for (int y = y_start; y < y_start + TILE_SIZE; y++)
//             {
//                 for (int x = x_start; x < x_start + TILE_SIZE; x++)
//                 {
//                     mlx_pixel_put(mlx->intro, mlx->window, x, y, color);
//                 }
//             }
//             j++;
//         }
//         i++;
//     }
// }

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
	// if (x >= 0 && x < img->width && y >= 0 && y < img->height)
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
	if (data->map[i][j] == '0' || data->map[i][j] == 'N')
		draw_tile(i, j, &mlx->img, 0xAAAAAA);
	else if (data->map[i][j] == '1')
		draw_tile(i, j, &mlx->img, 0xFF0000);
	else if (data->map[i][j] == ' ')
		draw_tile(i, j, &mlx->img, 0x000000);
	else
		draw_tile(i, j, &mlx->img, 0xAAAAAA);
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
	mlx_put_image_to_window(mlx->intro, mlx->window, mlx->img.img, 0, 0);
}

void draw_player(t_minilibx *mlx, t_global *data)
{
	int i = 0;
	int j;
	int c;
	int b = -1;
	while(data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
			{
				mlx->player.px = j;
				mlx->player.py = i;
				while (++b < TILE_SIZE / 3)
				{
					c = -1;
					while(++c < TILE_SIZE / 3)
						mlx_pixel_put(mlx->intro, mlx->window, mlx->player.px * TILE_SIZE + c, mlx->player.py * TILE_SIZE + b, 0xFFFFFF);
				}
			}
			j++;
		}
		i++;
	}
}

void	start_game(t_minilibx *mlx, t_global *data)
{
	create_map(mlx, data);
	draw_player(mlx, data);
	// mlx_hook(mlx->window, 02, (1L<<0), key_routine, mlx);
}

int	mlx_intro(t_minilibx *mlx, t_global *global)
{
	mlx->intro = mlx_init();
	if (!mlx->intro)
		return (1);
	mlx->window = mlx_new_window(mlx->intro, TILE_SIZE * global->map_width, TILE_SIZE * global->map_lenght, "cub3d");
	mlx->img.img = mlx_new_image(mlx->intro, TILE_SIZE * global->map_width, TILE_SIZE * global->map_lenght);
	if (!mlx->img.img)
		return (1);
	mlx->img.pixel_ptr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_lenght, &mlx->img.endian);
	return (0);
}

int	main(int ac, char **av)
{
	t_global	*global;
	t_minilibx	mlx;

	global = (t_global *)calloc(1, sizeof(t_global));
	if (global == NULL)
		error_print("Failed to allocate memory");
	pars(global, ac, av);
	if (mlx_intro(&mlx, global))
		return (free(global),0);
	start_game(&mlx, global);
	mlx_loop(mlx.intro);
}
