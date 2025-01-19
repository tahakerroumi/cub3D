/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:52:13 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 20:01:04 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	check_textures_extention(t_global *global)
{
	if (open(global->no_path, O_RDWR) == -1)
	{
		free_global(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->so_path, O_RDWR) == -1)
	{
		free_global(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->we_path, O_RDWR) == -1)
	{
		free_global(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->ea_path, O_RDWR) == -1)
	{
		free_global(global);
		error_print("Error\ncheck ur textures files\n");
	}
}

void	map_size2(t_global *global)
{
	int	i;
	int	max;
	int	tmp;

	i = 0;
	max = 0;
	tmp = 0;
	global->map_height = ft_doublepointerlen(global->real_map);
	while (global->real_map[i])
	{
		tmp = ft_strlen(global->real_map[i]);
		if (tmp > max)
			max = tmp;
		else
			i++;
	}
	global->map_width = max;
}

int	checkextention(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4)
		return (-1);
	if (ft_strncmp(".cub", str + len - 4, 4) != 0)
		return (-1);
	return (1);
}

int	main(int ac, char **av)
{
	t_global	*global;
	t_minilibx	mlx;
	int			fd;

	if (ac != 2)
		error_print("Error\ncheck your arguments\n");
	global = (t_global *)malloc(sizeof(t_global));
	if (!global)
		error_print("Error\nFailed to allocate memory \n");
	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		error_print("Error\nFile not found\n");
	else if (checkextention(av[1]) == -1)
		error_print("Error\nextention error \n");
	else
		parse_first_part(global, fd);
	if (mlx_intro(&mlx, global))
		return (free_elements(&mlx), 0);
	start_game(&mlx);
}
