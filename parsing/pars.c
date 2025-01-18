/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:47:23 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/18 12:33:23 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void	dbarray_free(char **str1, char **str2, char **str3, t_global *global)
{
	if (str1)
		ft_doublepointerfree(str2);
	if (str2)
		ft_doublepointerfree(str2);
	if (str3)
		ft_doublepointerfree(str3);
	if (global)
		free(global);
}

void	pars_norm(int ac, char **av, t_global *global)
{
	if (ac != 2)
	{
		free(global);
		error_print("Error\ncheck your arguments\n");
	}
	if (checkextention(av[1]) == -1)
	{
		free(global);
		error_print("Error\nextention error \n");
	}
}

void	normmm(t_elements *elements)
{
	free(elements->map);
	free(elements);
}

int checkbeforee(char **map)
{
	int i = 0;

	char *tmp;

	while(map[i])
	{
		tmp = ft_strtrim(map[i]);
		if(tmp[0] == '1')
		{
			free(tmp);
			return 1;
		}
		i++;
		free(tmp);
	}
	return (-1);
}
void	pars2norm(t_elements *elements, char **av, t_global *global)
{
	char		**file_content;
	char		**file_content2;
	char		**file_content3;

	file_content = map_to_doublepointer(av[1]);
	file_content2 = map_to_doublepointer(av[1]);
	file_content3 = map_to_doublepointer(av[1]);
	if (!file_content || !file_content3 || !file_content2)
		dbarray_free(file_content, file_content3, file_content2, global);
	checkbeforee(file_content2);
	if (check_elements(file_content, &elements) == -1 || checkbeforee(file_content2) == -1)
	{
		ft_doublepointerfree(file_content3);
		ft_doublepointerfree(file_content);
		ft_doublepointerfree(file_content2);
		free(elements);
		error_print("Error\nerror in the map or elements \n");
	}
	elements->map = fill_map(file_content2);
	if (fill_otherelements(file_content3, &global) == -1)
	{
		dbarray_free(file_content, file_content3, file_content2, NULL);
		normmm(elements);
		error_print("Error\ncheck the top of your map \n");
	}
	ft_doublepointerfree(file_content3);
	ft_doublepointerfree(file_content);
	ft_doublepointerfree(file_content2);
}

void	pars(t_global *global, int ac, char **av)
{
	t_elements	*elements;

	pars_norm(ac, av, global);
	elements = (t_elements *)calloc(1, sizeof(t_elements));
	if (elements == NULL)
	{
		free(global);
		error_print("Error\nFailed to allocate memory\n");
	}
	pars2norm(elements, av, global);
	global->map = doublepointercopy(elements->map);
	free(elements);
}
