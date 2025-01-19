/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functios.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:53:28 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 17:53:29 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_global(t_global *global)
{
	if (global->map)
		ft_doublepointerfree(global->map);
	if (global->real_map)
		ft_doublepointerfree(global->real_map);
	if (global->no)
		free(global->no);
	if (global->so)
		free(global->so);
	if (global->we)
		free(global->we);
	if (global->ea)
		free(global->ea);
	if (global->no_path)
		free(global->no_path);
	if (global->so_path)
		free(global->so_path);
	if (global->we_path)
		free(global->we_path);
	if (global->ea_path)
		free(global->ea_path);
	if (global->f)
		free(global->f);
	if (global->c)
		free(global->c);
	free(global);
}

size_t	ft_countwords(char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

size_t	ft_getwordlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

void	ft_freearray(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}
