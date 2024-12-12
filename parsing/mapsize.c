/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:34 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/11 15:22:04 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/headerfile.h"

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
	global->cr = ft_atoi(tmp[0]);
	global->cg = ft_atoi(tmp[1]);
	global->cb = ft_atoi(tmp[2]);
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->f, ',');
	global->fr = ft_atoi(tmp[0]);
	global->fg = ft_atoi(tmp[1]);
	global->fb = ft_atoi(tmp[2]);
	ft_doublepointerfree(tmp);
}
