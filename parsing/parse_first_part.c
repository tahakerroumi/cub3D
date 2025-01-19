/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:57:43 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 18:33:48 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	check_extentions_format(t_global *global)
{
	char	**tmp;

	tmp = ft_split(global->no, ' ');
	if (ft_doublepointerlen(tmp) != 2)
	{
		ft_doublepointerfree(tmp);
		free_global(global);
		error_print("Error\ncheck your elements!\n");
	}
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->so, ' ');
	if (ft_doublepointerlen(tmp) != 2)
	{
		free_global(global);
		ft_doublepointerfree(tmp);
		error_print("Error\ncheck your elements!\n");
	}
	ft_doublepointerfree(tmp);
}

void	check_extentions_format2(t_global *global)
{
	char	**tmp;

	tmp = ft_split(global->we, ' ');
	if (ft_doublepointerlen(tmp) != 2)
	{
		ft_doublepointerfree(tmp);
		free_global(global);
		error_print("Error\ncheck your elements!\n");
	}
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->ea, ' ');
	if (ft_doublepointerlen(tmp) != 2)
	{
		ft_doublepointerfree(tmp);
		free_global(global);
		error_print("Error\ncheck your elements!\n");
	}
	ft_doublepointerfree(tmp);
}

void	get_textures_path(t_global *global)
{
	char	**tmp;

	tmp = ft_split(global->no, ' ');
	global->no_path = ft_strdup(tmp[1]);
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->so, ' ');
	global->so_path = ft_strdup(tmp[1]);
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->ea, ' ');
	global->ea_path = ft_strdup(tmp[1]);
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->we, ' ');
	global->we_path = ft_strdup(tmp[1]);
	ft_doublepointerfree(tmp);
}

void	che_rgb_number(t_global *global)
{
	int		i;
	int		def;
	char	*tmp;

	i = 0;
	def = 0;
	while (global->map[i])
	{
		tmp = ft_strtrim(global->map[i]);
		if (ft_strncmp(tmp, "NO ", 3) == 0 || ft_strncmp(tmp, "SO ", 3) == 0
			|| ft_strncmp(tmp, "EA ", 3) == 0 || ft_strncmp(tmp, "WE ", 3) == 0
			|| ft_strncmp(tmp, "F ", 2) == 0 || ft_strncmp(tmp, "C ", 2) == 0)
		{
			def += 1;
			free(tmp);
		}
		else
			free(tmp);
		i++;
	}
	if (def != 6)
		error_print("Error\nWrong element input\n");
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

void	parse_first_part(t_global *global, int fd)
{
	init(global);
	global->map = fill_map(fd);
	che_rgb_number(global);
	get_infos_from_map(global->map, global);
	check_extentions_format(global);
	check_extentions_format2(global);
	check_rgb_format(global);
	check_rgb_format1(global);
	store_rgb(global);
	check_emptymap(global);
	check_emptymap2(global);
	get_realmap(global, map_size(global));
	check_for_unwanted_chars(global);
	check_emptyline(global);
	check_walls(global);
	player_exists(global);
	map_size2(global);
	check_for_textures_extension(global);
	get_textures_path(global);
	check_textures_extention(global);
}
