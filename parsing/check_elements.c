/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:58:01 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/16 15:38:37 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int	ft_doublepointerlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_elements(char **map, t_elements **elements)
{
	char	*tmp1;
	char	**tmp;
	int		i;

	i = 0;
	**elements = (typeof(**elements)){0};//make another function to init this struct
	while (map[i])
	{
		tmp1 = ft_strtrim(map[i]);
		if (tmp1 && tmp1[0] != '\0')
		{
			tmp = ft_split(tmp1, ' ');
			if (elements_are_mixed(tmp[0]) == -1)
			{
				ft_doublepointerfree(tmp);
				break ;
			}
			compare_texture(tmp, elements);
			compare_floorcellingcolor(tmp, elements);
			ft_doublepointerfree(tmp);
		}
		i++;
		free(tmp1);
	}
	free(tmp1);
	return (check_elementsnumber(*elements));
}

void	check_fc(t_global *global)
{
	char	**tmp;
	char	**tmp2;

	tmp = ft_split(global->c, ',');
	if (ft_doublepointerlen(tmp) != 3)
		error_print("Error\nelements problem\n");//must free global and global map and tmp *******************************************************************
	if (ft_atoi(tmp[0]) < 0
		|| ft_atoi(tmp[0]) > 255
		|| ft_atoi(tmp[1]) < 0
		|| ft_atoi(tmp[1]) > 255
		|| ft_atoi(tmp[2]) < 0
		|| ft_atoi(tmp[2]) > 255)
	{
		ft_doublepointerfree(tmp);
		error_print("Error\nelements problem\n");//must free global and global map *******************************************************************
	}
	tmp2 = ft_split(global->f, ',');
	if (ft_doublepointerlen(tmp2) != 3)
		error_print("Error\nelements problem\n");//must free global and global map and tmp2*******************************************************************
	if (ft_atoi(tmp2[0]) < 0
		|| ft_atoi(tmp2[0]) > 255
		|| ft_atoi(tmp2[1]) < 0
		|| ft_atoi(tmp2[1]) > 255
		|| ft_atoi(tmp2[2]) < 0
		|| ft_atoi(tmp2[2]) > 255)
		{
			ft_doublepointerfree(tmp);
			error_print("Error\nelements problem\n");//must free global and global map*******************************************************************
		}
	ft_doublepointerfree(tmp);
	ft_doublepointerfree(tmp2);
}
