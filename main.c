/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:22 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/13 23:01:45 by abakhcha         ###   ########.fr       */
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

void create_map(t_minilibx *mlx, t_global *data)
{
    int i, j; // Size of each tile

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            int x_start = j * TILE_SIZE; // Top-left corner x-coordinate of the tile
            int y_start = i * TILE_SIZE; // Top-left corner y-coordinate of the tile
            int color;

            // Determine the color based on the map value
            if (data->map[i][j] == '1')
                color = 0xFF0000; // Red for '1'
            else if (data->map[i][j] == '0' || data->map[i][j] == 'N')
                color = 0xAAAAAA; // Transparent gray for '0' (approximation with light gray)
            // else if (data->map[i][j] == 'N')
            //     color = 0x0000FF; // Blue for 'N'
            else if (data->map[i][j] == ' ')
                color = 0x000000; // Black for space
            else
                color = 0x000000; // Default to white for any other value (optional)

            // Draw the full tile
            for (int y = y_start; y < y_start + TILE_SIZE; y++) // Iterate over tile height
            {
                for (int x = x_start; x < x_start + TILE_SIZE; x++) // Iterate over tile width
                {
                    mlx_pixel_put(mlx->intro, mlx->window, x, y, color);
                }
            }
            j++; // Move to the next tile in the row
        }
        i++; // Move to the next row of tiles
    }
}


void draw_player(t_minilibx *mlx, t_global *data)
{
	int i = 0;
	int j;
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
					int c = -1;
					while(++c < TILE_SIZE / 3)
					{
						mlx_pixel_put(mlx->intro, mlx->window, mlx->player.px * TILE_SIZE + c, mlx->player.py * TILE_SIZE + b, 0xFFFFFF);
					}
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
	// (void)global;
	mlx->intro = mlx_init();
	if (!mlx->intro)
		return (1);
	mlx->window = mlx_new_window(mlx->intro, TILE_SIZE * global->map_width, TILE_SIZE * global->map_lenght, "cub3d");
	mlx->img.img = mlx_new_image(mlx->intro, TILE_SIZE * global->map_width, TILE_SIZE * global->map_lenght);
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
	if (mlx_intro(&mlx, global))
		return (free(global),0);
	start_game(&mlx, global);
	mlx_loop(mlx.intro);
}
