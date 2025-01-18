/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:22 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/18 13:09:07 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/headerfile.h"

#include "inc/headerfile.h"

int	comparaison2(char *str)
{
	char *tmp;

	tmp = ft_strtrim(str);
	if (ft_strncmp(tmp, "NO", 2) == 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "SO", 2) == 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "WE", 2) == 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "EA", 2) == 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "F", 1) == 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "C", 1) == 0)
		return (free(tmp),-1);
	return (free(tmp),1);
}

char	**doubleptr_strim2(char **str, char **map, int end, int start)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		map[i] = ft_strdup(str[start]);
		if (!map[i])
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		start++;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**doubleptr_strim(char **str, int end)
{
	char	**map;
	int		i;
	int size;
	int start;
	char	*trimmed;
	char *tmp;
	
	i = 0;
	size = 0;
	start = 0;
	if (!str || end < 0)
		return (NULL);
	while (str[i])
	{
		tmp = ft_strtrim(str[i]);

		if(tmp != NULL && (comparaison2(str[i]) == -1 || ft_strncmp(tmp, "\0", 2) == 0))
		{
			free(tmp);
			size++;
			i++;
		}
		else
		{
			if(tmp)
				free(tmp);
			break;
		}
	}
	start = size;
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
	if (end < start)
		return (NULL);
	map = malloc((end - start + 2) * sizeof(char *));
	if (!map)
		return (NULL);
	return (doubleptr_strim2(str, map, end, start));
}

int	comparaison(char *str)
{
	char *tmp;

	tmp = ft_strtrim(str);
	if (ft_strncmp(tmp, "NO", 2) != 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "SO", 2) != 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "WE", 2) != 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "EA", 2) != 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "F", 1) != 0)
		return (free(tmp),-1);
	if (ft_strncmp(tmp, "C", 1) != 0)
		return (free(tmp),-1);
	return (free(tmp),1);
}

int	main(int ac, char **av)
{
	t_global	*global;
	t_minilibx	mlx;

	global = (t_global *)calloc(1, sizeof(t_global));
	if (global == NULL)
		error_print("Error\nFailed to allocate memory");

	pars(global, ac, av);
	pars2(global);
	map_size(global);
	store_rgb(global);
	
	
	if (mlx_intro(&mlx, global))
		return (free_elements(&mlx), 0);


	start_game(&mlx);
	
}
