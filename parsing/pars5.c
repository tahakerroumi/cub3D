#include "../includes/cub3d.h"

void	check_rgb_format(t_global *global)
{
	char	**tmp1;
	int		i;
	char	**tmp2;

	i = 0;
	if (rgb_format(global->c + 1) == -1)
	{
		free_global(global);
		error_print("Error\nCheck your RGB format\n");
	}
	tmp1 = ft_split(global->c + 1, ',');
	while (tmp1[i])
	{
		if (ft_atoi(tmp1[i]) > 255)
		{
			ft_doublepointerfree(tmp1);
			error_print("Error\nCheck your RGB values\n");
		}
		tmp2 = ft_split(tmp1[i], ' ');
		if (!tmp2)
		{
			ft_doublepointerfree(tmp1);
			error_print("Error\nMemory allocation failed\n");
		}
		if (ft_doublepointerlen(tmp2) != 1)
		{
			ft_doublepointerfree(tmp2);
			ft_doublepointerfree(tmp1);
			error_print("Error\nCheck your RGB format\n");
		}
		ft_doublepointerfree(tmp2);
		i++;
	}
	ft_doublepointerfree(tmp1);
}

void	check_rgb_format1(t_global *global)
{
	char	**tmp1;
	int		i;
	char	**tmp2;

	i = 0;
	if (rgb_format(global->f + 1) == -1)
	{
		free_global(global);
		error_print("Error\nCheck your RGB format\n");
	}
	tmp1 = ft_split(global->f + 1, ',');
	while (tmp1[i])
	{
		if (ft_atoi(tmp1[i]) > 255)
		{
			ft_doublepointerfree(tmp1);
			error_print("Error\nCheck your RGB values\n");
		}
		tmp2 = ft_split(tmp1[i], ' ');
		if (!tmp2)
		{
			ft_doublepointerfree(tmp1);
			error_print("Error\nMemory allocation failed\n");
		}
		if (ft_doublepointerlen(tmp2) != 1)
		{
			ft_doublepointerfree(tmp2);
			ft_doublepointerfree(tmp1);
			error_print("Error\nCheck your RGB format\n");
		}
		ft_doublepointerfree(tmp2);
		i++;
	}
	ft_doublepointerfree(tmp1);
}

void	store_rgb(t_global *global)
{
	char	**tmp;

	tmp = ft_split(global->c + 1, ',');
	global->ceiling_red = ft_atoi(tmp[0]);
	global->ceiling_green = ft_atoi(tmp[1]);
	global->ceiling_blue = ft_atoi(tmp[2]);
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->f + 1, ',');
	global->floor_red = ft_atoi(tmp[0]);
	global->floor_green = ft_atoi(tmp[1]);
	global->floor_blue = ft_atoi(tmp[2]);
	ft_doublepointerfree(tmp);
}

void	check_for_textures_extension(t_global *global)
{
	if (ft_strncmp(global->so + ft_strlen(global->so) - 4, ".xpm", 4) != 0)
	{
		free_global(global);
		error_print("Error\nSO texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->no + ft_strlen(global->no) - 4, ".xpm", 4) != 0)
	{
		free_global(global);
		error_print("Error\nNO texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->we + ft_strlen(global->we) - 4, ".xpm", 4) != 0)
	{
		free_global(global);
		error_print("Error\nWE texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->ea + ft_strlen(global->ea) - 4, ".xpm", 4) != 0)
	{
		free_global(global);
		error_print("Error\nEA texture must be a .xpm file\n");
	}
}