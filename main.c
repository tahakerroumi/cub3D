/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:22 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/26 18:52:12 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/headerfile.h"

int	comparaison2(char *str)
{
	if (ft_strncmp(ft_strtrim(str), "NO", 2) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "SO", 2) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "WE", 2) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "EA", 2) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "F", 1) == 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "C", 1) == 0)
		return (-1);
	return (1);
}

char	**doubleptr_strim2(char **str, char **map, int end, int start)
{
	int	i;

	i = -1;
	while (start <= end)
	{
		map[i++] = ft_strdup(str[start]);
		start++;
	}
	map[i] = NULL;
	return (map);
}

char	**doubleptr_strim(char **str, int end)
{
	char	**map;
	int		i;
	int		size;
	int		start;

	i = 0;
	size = 0;
	start = 0;
	while (str[i++] && (comparaison2(str[i]) == -1
			|| ft_strncmp
			(ft_strtrim(str[i]), "\0", 2) == 0))
		size++;
	start = size;
	if (str[end] == NULL)
		end--;
	i = end;
	while (end > start && ft_strncmp(ft_strtrim(str[i--]), "\0", 2) == 0)
		end--;
	map = malloc((end - start + 2) * sizeof(char *));
	if (!map)
		return (NULL);
	return (doubleptr_strim2(str, map, end, start));
}

int	comparaison(char *str)
{
	if (ft_strncmp(ft_strtrim(str), "NO", 2) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "SO", 2) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "WE", 2) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "EA", 2) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "F", 1) != 0)
		return (-1);
	if (ft_strncmp(ft_strtrim(str), "C", 1) != 0)
		return (-1);
	return (1);
}

int	main(int ac, char **av)
{
	t_global	*global;
	t_minilibx	mlx;

	global = (t_global *)calloc(1, sizeof(t_global));
	if (global == NULL)
		error_print("Failed to allocate memory");
	mlx.data = global;
	pars(global, ac, av);
	if (mlx_intro(&mlx, global))
		return (free(global),0);
	start_game(&mlx);
}
