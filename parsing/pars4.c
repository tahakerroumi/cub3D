/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:45:21 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/19 19:46:29 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	chek_walls2(t_global *global, int i, int j)
{
	if ((global->real_map[i][j] == '0' || global->real_map[i][j] == 'E'
			|| global->real_map[i][j] == 'W' || global->real_map[i][j] == 'N'
			|| global->real_map[i][j] == 'S') && (j == 0 || i == 0
			|| global->real_map[i + 1] == NULL || global->real_map[i][j
			+ 1] == '\0' || global->real_map[i - 1][j] == ' '
			|| global->real_map[i + 1][j] == ' ' || global->real_map[i][j
			- 1] == ' ' || global->real_map[i][j + 1] == ' '))
		return (1);
	return (-1);
}

void	check_walls(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (global->real_map[i])
	{
		j = 0;
		while (global->real_map[i][j])
		{
			if (chek_walls2(global, i, j) == 1)
			{
				error_print("Error\ncheck ur walls pls\n");
			}
			if (global->real_map[i][j] == '0' && (!global->real_map[i][j + 1]
					|| !global->real_map[i - 1][j] || !global->real_map[i
					+ 1][j] || !global->real_map[i][j - 1]))
			{
				error_print("Error\ncheck ur walls pls\n");
			}
			j++;
		}
		i++;
	}
}

void	check_emptyline(t_global *global)
{
	int		i;
	char	*tmp;

	i = 0;
	while (global->real_map[i])
	{
		tmp = ft_strtrim(global->real_map[i]);
		if (tmp[0] == '\0')
		{
			free(tmp);
			error_print("Error\nemptyline\n");
		}
		free(tmp);
		i++;
	}
}

int	rgb_format(char *str)
{
	int	def;
	int	i;

	i = 1;
	def = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else if (str[i] == ',' && ((str[i - 1] >= '0' && str[i - 1] <= '9')
				|| str[i - 1] == ' '))
		{
			def += 1;
			i++;
		}
		else
			break ;
	}
	if (str[i] == '\0' && def == 2)
		return (1);
	return (-1);
}
