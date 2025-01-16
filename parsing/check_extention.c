/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:01:01 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/16 20:51:36 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void	check_for_textures_extension(t_global *global)
{
	if (ft_strncmp(global->so + ft_strlen(global->so) - 4, ".xpm", 4) != 0)
	{
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\nSO texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->no + ft_strlen(global->no) - 4, ".xpm", 4) != 0)
	{
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\nNO texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->we + ft_strlen(global->we) - 4, ".xpm", 4) != 0)
	{
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\nWE texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->ea + ft_strlen(global->ea) - 4, ".xpm", 4) != 0)
	{
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\nEA texture must be a .xpm file\n");
	}
}

void norp(t_global *global, char *str)
{
	ft_doublepointerfree(global->map);
	free(global);
	error_print(str);
}

void	check_for_unwanted_chars(t_global *global)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (global->map[i])
	{
		j = 0;
		tmp = ft_strtrim(global->map[i]);
		if (ft_strlen(tmp) == 0)
		{
			free(tmp);
			ft_doublepointerfree(global->map);
			free(global);
			error_print("Error\nempty line in the map\n");
		}
		free(tmp);
		while (global->map[i][j])
		{
			if (global->map[i][j] != '1' && global->map[i][j] !=
			'0' && global->map[i][j] != 'N' && global->map[i][j] !=
			'S' && global->map[i][j] != 'W' && global->map[i][j] !=
			'E' && global->map[i][j] != ' ')
				norp(global, "Error\nUnwanted character in map\n");
			j++;
		}
		i++;
	}
}

int	chek_walls2(t_global *global, int i, int j)
{
	if ((global->map[i][j] == '0'
		|| global->map[i][j] == 'E'
		|| global->map[i][j] == 'W'
		|| global->map[i][j] == 'N'
		|| global->map[i][j] == 'S')
		&& (j == 0 || i == 0 || global->map[i + 1] == NULL
		|| global->map[i][j + 1] == '\0'
		|| global->map[i - 1][j] == ' '
		|| global->map[i + 1][j] == ' '
		|| global->map[i][j - 1] == ' '
		|| global->map[i][j + 1] == ' '))
		return (1);
	return (-1);
}

void	check_walls(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (chek_walls2(global, i, j) == 1)
				error_print("Error\ncheck ur walls pls\n");//must free global and global map*******************************************************************
			if (global->map[i][j] == '0'
				&& (!global->map[i][j + 1]
				|| !global->map[i - 1][j]
				|| !global->map[i + 1][j]
				|| !global->map[i][j - 1]))
			{
				error_print("Error\ncheck ur walls pls2\n");//must free global and global map*******************************************************************
			}
			j++;
		}
		i++;
	}
}


