/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerexists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:36:06 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/16 14:44:23 by tkerroum         ###   ########.fr       */
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
		error_print("the player is surronded\n");//must free global and global map*******************************************************************
	}
	if (playeri == 0 || playeri == i - 1 || !global->map[playeri][playerj + 1]
	|| !global->map[playeri - 1][playerj] || !global->map[playeri + 1][playerj]
	|| !global->map[playeri][playerj - 1])
	{
		error_print("check the player position\n");//must free global and global map*******************************************************************
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

void	if_p(int p)
{
	if (p != 1)
		error_print("check the players number\n");//must free global and global map*******************************************************************
}

void	palyer_exists(t_global *global)
{
	int	i;
	int	j;
	int	p;
	int	playeri = 0;
	int	playerj = 0;

	i = 0;
	p = 0;
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (conditionn(i, j, global) == 1)
			{
				p += 1;
				playeri = i;
				playerj = j;
			}
			j++;
		}
		i++;
	}
	if_p(p);
	player_exists2(playeri, playerj, global, i);
}
