/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerexists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:36:06 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/17 20:01:30 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void	player_exists2(int playeri, int playerj, t_global *global, int i)
{
	if ((global->map[playeri][playerj] == 'E'
		|| global->map[playeri][playerj] == 'W'
	|| global->map[playeri][playerj] == 'N'
		|| global->map[playeri][playerj] == 'S')
	&& (global->map[playeri][playerj + 1] == '1'
		&& global->map[playeri - 1][playerj] == '1'
	&& global->map[playeri + 1][playerj] == '1'
		&& global->map[playeri][playerj - 1] == '1'))
	{
		free(global->map);
		free(global);
		error_print("Error\nthe player is surronded\n");
	}
	if (playeri == 0 || playeri == i - 1 || !global->map[playeri][playerj + 1]
	|| !global->map[playeri - 1][playerj] || !global->map[playeri + 1][playerj]
	|| !global->map[playeri][playerj - 1])
	{
		free(global->map);
		free(global);
		error_print("Error\ncheck the player position\n");
	}
}

int	conditionn(int i, int j, t_global *global)
{
	if (global->map[i][j] == 'N'
	|| global->map[i][j] == 'S'
	|| global->map[i][j] == 'W'
	|| global->map[i][j] == 'E')
	{
		return (1);
	}
	return (-1);
}

void	if_p(int p, t_global *global)
{
	if (p != 1)
	{
		free(global->map);
		free(global);
		error_print("Error\ncheck the players number or map\n");
	}
}

void	palyer_exists(t_global *global)
{
	int	i;
	int	j;
	int	p;
	int	playeri;
	int	playerj;

	i = -1;
	p = 0;
	playeri = 0;
	playerj = 0;
	while (global->map[++i])
	{
		j = -1;
		while (global->map[i][++j])
		{
			if (conditionn(i, j, global) == 1)
			{
				p += 1;
				playeri = i;
				playerj = j;
			}
		}
	}
	if_p(p, global);
	player_exists2(playeri, playerj, global, i);
}
