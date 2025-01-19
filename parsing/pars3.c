/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:40:01 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/19 19:48:58 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	if_z(int z, t_global *global)
{
	if (z == 0)
	{
		free_global(global);
		error_print("Error\nmap does not exitst or walls != 1\n");
	}
}

void	check_emptymap(t_global *global)
{
	int		i;
	int		z;
	char	*tmp;

	i = global->index;
	z = 0;
	while (global->map[i])
	{
		tmp = ft_strtrim(global->map[i]);
		if (tmp[0] == '1')
		{
			z += 1;
			global->mapstart = i;
			free(tmp);
			break ;
		}
		else if (tmp[0] != '\0')
		{
			(free(tmp), free_global(global));
			error_print("Error\ncheck the file that contains the map\n");
		}
		free(tmp);
		i++;
	}
	if_z(z, global);
}

void	check_emptymap2(t_global *global)
{
	int		i;
	int		z;
	char	*tmp;

	i = ft_doublepointerlen(global->map) - 1;
	z = 0;
	while (i >= global->mapstart)
	{
		tmp = ft_strtrim(global->map[i]);
		if (tmp[0] == '1')
		{
			z += 1;
			global->mapend = i;
			free(tmp);
			break ;
		}
		else if (tmp[0] != '\0')
		{
			(free(tmp), free_global(global));
			error_print("Error\ncheck the file that contains the map\n");
		}
		free(tmp);
		i--;
	}
	if_z(z, global);
}

void	player_exists(t_global *global)
{
	int	i;
	int	j;
	int	def;

	i = 0;
	def = 0;
	while (global->real_map[i])
	{
		j = 0;
		while (global->real_map[i][j])
		{
			if (global->real_map[i][j] == 'N' || global->real_map[i][j] == 'S'
				|| global->real_map[i][j] == 'W'
				|| global->real_map[i][j] == 'E')
			{
				def += 1;
			}
			j++;
		}
		i++;
	}
	if (def != 1)
		error_print("Error\ncheck the player\n");
}

void	check_for_unwanted_chars(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	while (global->real_map[i])
	{
		j = 0;
		while (global->real_map[i][j])
		{
			if (global->real_map[i][j] != '1' && global->real_map[i][j] != '0'
				&& global->real_map[i][j] != 'N'
				&& global->real_map[i][j] != 'S'
				&& global->real_map[i][j] != 'W'
				&& global->real_map[i][j] != 'E'
				&& global->real_map[i][j] != ' ')
				error_print("Error\nUnwanted character in map\n");
			j++;
		}
		i++;
	}
}
