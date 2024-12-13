/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:22 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/13 20:56:37 by tkerroum         ###   ########.fr       */
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

void	draw_pixel(t_minilibx *mlx, t_global *data, int x, int y)
{
	int i;
	int	j;

	int offset_x = x * TILE_SIZE;
    int offset_y = y * TILE_SIZE;
	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
		{
			if (data->map[y][x] == '1')
				mlx_pixel_put(mlx->intro, mlx->window, offset_x + i, offset_y + j, 0xFF0000);
			else if (data->map[y][x] == '0')
				mlx_pixel_put(mlx->intro, mlx->window, offset_x + i, offset_y + j, 0xFFFFFF);
			// else if (data->map[y][x] == ' ')
			
		}
	}
}

void	create_map(t_minilibx *mlx, t_global *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_width * TILE_SIZE)
	{
		x = -1;
		while (++x < data->map_lenght * TILE_SIZE)
			draw_pixel(mlx, data, x, y);
	}
}

void	draw_player(t_minilibx *mlx)
{
	int	i, j;

	mlx->player.px = TILE_SIZE + (TILE_SIZE / 2);
	mlx->player.py = TILE_SIZE + (TILE_SIZE / 2);
	i = 0;
	while (i < TILE_SIZE / 2)
	{
		j = 0;
		while (j < TILE_SIZE / 2)
		{
			mlx_pixel_put(mlx->intro, mlx->window, mlx->player.py + i, mlx->player.px + j, 0xDFFF00);
			j++;
		}
		i++;
	}
	// int i = 0;
	// int j = 0;

	// while(i < global->map_lenght)
	// {
	// 	j = 0;
	// 	while(i < global->map_lenght)
	// 	{
	// 		if()
	// 		else
	// 		j++;
	// 	}
	// 	i++;
	// }
}

int	key_routine(int keycode, t_minilibx *mlx)
{
	(void )mlx;
	printf("%d\n", keycode);
	return 0;
}

void	start_game(t_minilibx *mlx, t_global *data)
{
	create_map(mlx, data);
	draw_player(mlx);
	mlx_hook(mlx->window, 02, (1L<<0), key_routine, mlx);
}

int	mlx_intro(t_minilibx *mlx)
{
	mlx->intro = mlx_init();
	if (!mlx->intro)
		return (1);
	mlx->window = mlx_new_window(mlx->intro, 90 * TILE_SIZE, 90 * TILE_SIZE, "cub3d");
	mlx->img.img = mlx_new_image(mlx->intro, 90 * TILE_SIZE, 90 * TILE_SIZE);
	if (!mlx->img.img)
		return (1);
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
	if (mlx_intro(&mlx))
		return (free(global),0);
	start_game(&mlx, global);
	mlx_loop(mlx.intro);
}
