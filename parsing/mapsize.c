/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:34 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/16 19:57:49 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void	map_size(t_global *global)
{
	int	i;
	int	max;
	int	tmp;

	i = 0;
	max = 0;
	tmp = 0;
	global->map_height = ft_doublepointerlen(global->map);
	while (global->map[i])
	{
		tmp = ft_strlen(global->map[i]);
		if (tmp > max)
			max = tmp;
		else
			i++;
	}
	global->map_width = max;
}

void	store_rgb(t_global *global)
{
	char	**tmp;

	tmp = ft_split(global->c, ',');
	global->ceiling_red = ft_atoi(tmp[0]);
	global->ceiling_green = ft_atoi(tmp[1]);
	global->ceiling_blue = ft_atoi(tmp[2]);
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->f, ',');
	global->floor_red = ft_atoi(tmp[0]);
	global->floor_green = ft_atoi(tmp[1]);
	global->floor_blue = ft_atoi(tmp[2]);
	free(global->c);
	free(global->f);
	ft_doublepointerfree(tmp);
}
