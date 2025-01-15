/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:22 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/09 17:30:39 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/headerfile.h"

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

	i = 0;
	while (start <= end)
	{
		map[i] = ft_strdup(str[start]); // Copy the string
		if (!map[i])                    // Check for strdup failure
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		start++;
		i++;
	}
	map[i] = NULL; // Properly terminate the array
	return (map);
}

char	**doubleptr_strim(char **str, int end)
{
	char	**map;
	int		i = 0, size = 0, start;
	char	*trimmed;

	i = 0, size = 0, start = 0;
	if (!str || end < 0) // Validate inputs
		return (NULL);
	// Calculate the start index
	while (str[i] && (comparaison2(str[i]) == -1
			|| ft_strncmp(ft_strtrim(str[i]), "\0", 2) == 0))
	{
		size++;
		i++;
	}
	start = size;
	// Adjust the end index
	if (str[end] == NULL)
		end--;
	while (end > start)
	{
		trimmed = ft_strtrim(str[end]);
		if (ft_strncmp(trimmed, "\0", 2) != 0)
		{
			free(trimmed);
			break ;
		}
		free(trimmed);
		end--;
	}
	// Allocate memory for the new array
	if (end < start)
		return (NULL); // No valid strings to copy
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
	pars(global, ac, av);
	if (mlx_intro(&mlx, global))
		return (free(global), 0);
	start_game(&mlx);
}
