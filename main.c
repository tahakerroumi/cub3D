/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:52:13 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 17:55:45 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	checkextention(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4)
		return (-1);
	if (ft_strncmp(".cub", str + len - 4, 4) != 0)
		return (-1);
	return (1);
}

int	main(int ac, char **av)
{
	t_global	*global;
	t_minilibx	mlx;
	int			fd;

	if (ac != 2)
		error_print("Error\ncheck your arguments\n");
	global = (t_global *)malloc(sizeof(t_global));
	if (!global)
		error_print("Error\nFailed to allocate memory \n");
	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		error_print("Error\nFile not found\n");
	else if (checkextention(av[1]) == -1)
		error_print("Error\nextention error \n");
	else
		parse_first_part(global, fd);
	if (mlx_intro(&mlx, global))
		return (free_elements(&mlx), 0);
	start_game(&mlx);
}
