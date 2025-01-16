/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:39:04 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/16 20:41:04 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void	check_textures_extention(t_global *global)
{
	if (open(global->no, O_RDWR) == -1)
	{
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->so, O_RDWR) == -1)
	{
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->we, O_RDWR) == -1)
	{
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->ea, O_RDWR) == -1)
	{
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\ncheck ur textures files\n");
	}
}
